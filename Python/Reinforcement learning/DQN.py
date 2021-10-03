import wandb
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
import tqdm
import gym
from gym.wrappers.monitoring.video_recorder import VideoRecorder

from time import time
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Input
from tensorflow.keras.optimizers import Adam
class ReplayBuffer():
	def __init__(self, size, observation_dims, action_dims):
		self.buffer_size = size
		
		self.obs_mem = np.zeros((self.buffer_size, observation_dims))
		self.next_obs_mem = np.zeros_like(self.obs_mem)
		self.action_mem = np.zeros(self.buffer_size, dtype=np.int64)
		self.reward_mem = np.zeros(self.buffer_size)
		self.terminal_mem = np.zeros(self.buffer_size, dtype=np.float32)

		self.buffer_cntr = 0

	def insert_exp(self, obse, obse_, actione, rewarde, terminale):
		index = int(self.buffer_cntr % self.buffer_size)

		self.obs_mem[index] = obse
		self.next_obs_mem[index] = obse_
		self.action_mem[index] = actione 
		self.reward_mem[index] = rewarde
		self.terminal_mem[index] = 1 - int(terminale)

		self.buffer_cntr +=1

	def get_exp(self, batch_size):
		max_size = int(min(self.buffer_cntr, self.buffer_size))
		batch = np.random.choice(max_size, batch_size)

		batch_obs = self.obs_mem[batch]
		batch_obs_ = self.next_obs_mem[batch]
		batch_action = self.action_mem[batch]
		batch_reward = self.reward_mem[batch]
		batch_terminal = self.terminal_mem[batch]

		return batch_obs, batch_obs_, batch_action, batch_reward, batch_terminal


def get_DQN(input_shape, output_shape, hidden_units, lr):
	model = Sequential()
	model.add(Input(shape=(input_shape,)))
	for units in hidden_units:
		model.add(Dense(units, activation='relu'))
	model.add(Dense(output_shape))

	model.compile(optimizer=Adam(lr=lr), loss='mse')
	return model

class Agent():
	def __init__(self, buffer_size, observation_dims, n_actions, 
				 batch_size=64, hidden_units=[256, 256], learning_rate=0.001, 
				 gamma=.99, epsilon=1.0, epsilon_dec=0.93, epsilon_min=0.01):

		self.buffer = ReplayBuffer(buffer_size, observation_dims, n_actions)
		self.dqn = get_DQN(observation_dims, n_actions, hidden_units, learning_rate)

		self.gamma = gamma
		self.e = epsilon
		self.e_dec = epsilon_dec
		self.e_min = epsilon_min
		
		self.action_array = np.arange(n_actions, dtype=np.int64)
		self.batch_size = batch_size

		self.optimizer = tf.keras.optimizers.Adam(learning_rate = learning_rate)

	def insert_exp(self, exp_obs, exp_obs_, exp_action, exp_reward, exp_terminal):
		self.buffer.insert_exp(exp_obs, exp_obs_, exp_action, exp_reward, exp_terminal)

	def get_action(self, observation):
		rand = np.random.random()
		observation = np.expand_dims(observation, 0)

		if rand < self.e:	
			return np.random.choice(self.action_array)
		q_vals = self.dqn.predict(observation)
		return np.argmax(q_vals)

	def learn(self):
		if self.buffer.buffer_cntr < self.batch_size:
			return
		observations, next_observations, actions, rewards, terminates = self.buffer.get_exp(self.batch_size)
		
		targets = self.dqn.predict(observations)
		Q_next = self.dqn.predict(next_observations)

		#targets = Q.copy()
		indices = np.arange(self.batch_size, dtype=np.int64)

		targets[indices, actions] = rewards + self.gamma * np.max(Q_next, axis=1) * terminates
		
		self.dqn.fit(observations, targets, verbose=0)


		self.e = self.e * self.e_dec if self.e > self.e_min else self.e_min
if __name__=='__main__':
	tf.compat.v1.disable_eager_execution()
	env = gym.make("CartPole-v0")
	state_dims = env.reset().shape[0]
	n_actions = env.action_space.n

	agent = Agent(buffer_size=64, observation_dims=state_dims, n_actions=n_actions)
	
	n_games = 500
	scores = []
	avg_scores = []
	wandb.init(project="CartPole")
	video_recorder = VideoRecorder(env, path="Results/DQN.mp4")
	with tqdm.trange(n_games) as t:
		for i in t:
			done = False
			score = 0
			s = env.reset()
			while not done:
				a = agent.get_action(s)
				s_, r, done, info = env.step(a)
				agent.insert_exp(s, s_, a, r, done)
				agent.learn()
				s = s_

				score += r

			scores.append(score)
			avg_score = np.mean(scores[max(0, i-50): (i+1)])
			avg_scores.append(avg_score)
			t.set_description(f"Episode= {i}")
			t.set_postfix(Average_reward = avg_score,
				 Buffer_Size = agent.buffer.buffer_cntr)
			wandb.log({"Average Reward": avg_scores[-1]})

	s = env.reset()
	for _ in range(200):
		a = agent.get_action(s)
		env.render()
		video_recorder.capture_frame()
		s, r, d, i = env.step(a)

	env.close()
	video_recorder.close()
	video_recorder.enabled = False