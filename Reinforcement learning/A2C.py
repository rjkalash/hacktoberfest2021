import tensorflow as tf
from tensorflow.keras.layers import Dense
from tensorflow.keras.models import Model
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.losses import MSE
import tensorflow_probability as tfp
import numpy as np
import matplotlib.pyplot as plt
import wandb
import tqdm
import gym
from gym.wrappers.monitoring.video_recorder import VideoRecorder

class Actor(Model):
	def __init__(self, n_actions):
		super(Actor, self).__init__()
		self.d1 = Dense(1024, activation='relu')
		self.d2 = Dense(512, activation='relu')
		self.pi = Dense(n_actions, activation='softmax')

	def __call__(self, inp):
		x = self.d1(inp)
		x = self.d2(x)
		return self.pi(x)

class Critic(Model):
	def __init__(self):
		super(Critic, self).__init__()
		self.d1 = Dense(1024, activation='relu')
		self.d2 = Dense(512, activation='relu')
		self.V = Dense(1)

	def __call__(self, inp):
		x = self.d1(inp)
		x = self.d2(x)
		return self.V(x)

class Agent():
	def __init__(self, n_actions, alpha, gamma):
		self.alpha = alpha
		self.gamma = gamma
		self.n_actions = n_actions

		self.actor = Actor(self.n_actions)
		self.critic = Critic()

		self.optimizer = Adam(learning_rate=self.alpha)
	
	@tf.function
	def get_action(self, obs):
		obs = tf.reshape(obs, (1, -1))
		probs = self.actor(obs)
		action_probs = tfp.distributions.Categorical(probs=probs)
		action = action_probs.sample()
		return action

	def get_returns(self, rewards, dones):
		G = 0.
		returns = []
		for i in reversed(rewards):
			G = i + self.gamma * G 
			returns.append(G)
		return np.array(returns[::-1], dtype=np.float32)*dones

	@tf.function
	def learn(self, states, actions, rewards):
		with tf.GradientTape(persistent=True) as tape:
			V = tf.squeeze(self.critic(states))
			CriticLoss = MSE(returns, V)
			preds = self.actor(states)
			action_preds = tfp.distributions.Categorical(probs=preds)
			log_probs = action_preds.log_prob(actions)
			ActorLoss = -tf.reduce_mean(log_probs*returns)

		actorGrads = tape.gradient(ActorLoss, self.actor.trainable_variables)
		criticGrads = tape.gradient(CriticLoss, self.critic.trainable_variables)

		self.optimizer.apply_gradients(zip(actorGrads, self.actor.trainable_variables))
		self.optimizer.apply_gradients(zip(criticGrads, self.critic.trainable_variables))
		return CriticLoss, ActorLoss

if __name__ == "__main__":
	
	env = gym.make("CartPole-v0")
	
	ALPHA = 0.0009
	GAMMA = 0.999
	N_ACTIONS = env.action_space.n
	
	agent = Agent(N_ACTIONS , ALPHA, GAMMA)

	wandb.init(project="CartPole")
	wandb.config.ALPHA = ALPHA
	wandb.config.GAMMA = GAMMA
	
	n_steps = 500
	
	video_recorder = VideoRecorder(env, "Results/A2C-CartPole.mp4")
	reward_mem = []
	for t in range(n_steps):
		states = []
		actions = []
		rewards = []
		next_states = []
		dones = []

		s = env.reset()
		done = False

		while not done:
			a = agent.get_action(s)[0].numpy()
			next_s, r, done, info = env.step(a)

			states.append(s)
			actions.append(a)
			rewards.append(r)
			next_states.append(next_s)
			dones.append(1-done)

			s = next_s

		states = np.array(states, dtype=np.float32)
		actions = np.array(actions, dtype=np.int64)
		rewards = np.array(rewards, dtype=np.float32)
		next_states = np.array(next_states, dtype=np.float32)
		dones = np.array(dones, dtype=np.float32)
		returns = agent.get_returns(rewards, dones)

		reward_mem.append(np.sum(rewards))
		Closs, Aloss = agent.learn(states, actions, rewards)
		
		wandb.log({"Critic Loss":Closs, "Actor Loss":Aloss, "Average Reward":np.mean(reward_mem[-50:])})
		print(f"Episode {t} : {np.sum(rewards)}")


	s = env.reset()
	for _ in range(200):
		a = agent.get_action(s)[0].numpy()
		env.render()
		video_recorder.capture_frame()
		next_s, r, done, info = env.step(a)

		s = next_s
	video_recorder.close()
	video_recorder.enabled = False
	env.close()