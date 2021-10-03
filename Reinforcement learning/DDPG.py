import numpy as np
import tensorflow as tf
import gym
import tqdm
import matplotlib.pyplot as plt
from tensorflow.keras.layers import Dense
from tensorflow.keras.models import Model
from tensorflow.keras.optimizers import Adam
import tensorflow_probability as tfp
import wandb
from gym.wrappers.monitoring.video_recorder import VideoRecorder
class ReplayBuffer:
	'''
	Replay Buffer: Stores and samples trajectrories (States, actions, rewards, next states and done flags)
	State and next state shapes : rank 1 tensor
	action, reward, doneflag shapes : rank 0 tensor
	'''
	def __init__(self, max_size, input_shape, n_actions):
		self.mem_size = max_size
		self.mem_cntr = 0
		self.state_memory = np.zeros((self.mem_size, input_shape), dtype=np.float32)
		self.new_state_memory = np.zeros_like(self.state_memory)
		self.action_memory = np.zeros((self.mem_size, n_actions))
		self.reward_memory = np.zeros(self.mem_size, dtype=np.float32)
		self.terminal_memory = np.zeros(self.mem_size, dtype=np.bool)

	def store_transition(self, state, action, reward, new_state, done):
		index = self.mem_cntr % self.mem_size

		self.state_memory[index] = state
		self.new_state_memory[index] = new_state
		self.action_memory[index] = action
		self.reward_memory[index] = reward
		self.terminal_memory[index] = done

		self.mem_cntr += 1

	def sample_buffer(self, batch_size):
		max_mem = min(self.mem_size, self.mem_cntr)
		batch = np.random.choice(max_mem, batch_size, replace=False)

		states = self.state_memory[batch]
		states_ = self.new_state_memory[batch]
		actions = self.action_memory[batch]
		rewards = self.reward_memory[batch]
		dones = self.terminal_memory[batch]

		return states, states_, actions, rewards, dones


class CriticNetwork(Model):
	'''
	CrtitcNetwork: a Dense NN for calculating Q values
	'''
	def __init__(self):
		super(CriticNetwork, self).__init__()

		self.d1 = Dense(1024, activation='relu')
		self.d2 = Dense(512, activation='relu')
		self.q_vals = Dense(1, activation=None)

	def __call__(self, obs, action=None, training=None):
		if training is not None:
			x = self.d1(obs)
		else:
			x = self.d1(tf.concat([obs, action], axis=1))
		x = self.d2(x)
		return self.q_vals(x)


class ActorNetwork(Model):
	'''
	ActorNetwork: a Dense NN for calculating mean actions
	'''
	def __init__(self, n_actions):
		super(ActorNetwork, self).__init__()

		self.n_actions = n_actions

		self.d1 = Dense(1024, activation='relu')
		self.d2 = Dense(512, activation='relu')
		self.mu = Dense(self.n_actions, activation='tanh')

	def __call__(self, obs, training=None):
		x = self.d1(obs)
		x = self.d2(x)
		mu = self.mu(x)
		
		return mu


class Agent:
	'''
	DDPG Agent Class:
	'''
	def __init__(self, input_dims, n_actions, env, max_size, batch_size, alpha, beta, gamma, tau, noise):
		self.gamma = gamma
		self.tau = tau
		self.learning_rate = alpha

		self.noise = noise

		self.memory = ReplayBuffer(max_size, input_dims, n_actions)
		self.batch_size = batch_size
		self.n_actions = n_actions
		self.obs_dims = input_dims
		self.max_action = env.action_space.high[0]
		self.min_action = env.action_space.low[0]

		self.actor = ActorNetwork(self.n_actions)
		self.critic = CriticNetwork()

		self.target_actor = ActorNetwork(self.n_actions)
		self.target_critic = CriticNetwork()

		self.target_actor.set_weights(self.actor.get_weights())
		self.target_critic.set_weights(self.critic.get_weights())

		self.actor.compile(optimizer=Adam(learning_rate=alpha))
		self.critic.compile(optimizer=Adam(learning_rate=beta), loss='mse')

		self.update_network_parameters(tau=1)


	def update_network_parameters(self, tau=None):
		if tau is None:
			tau = self.tau

		weights = []
		targets = self.target_actor.weights
		for i, weight in enumerate(self.actor.weights):
			weights.append(weight * tau + targets[i] * (1 - tau))
		self.target_actor.set_weights(weights)

		weights = []
		targets = self.target_critic.weights
		for i, weight in enumerate(self.critic.weights):
			weights.append(weight * tau + targets[i] * (1 - tau))

		self.target_critic.set_weights(weights)


	def remember(self, state, action, reward, new_state, done):
		self.memory.store_transition(state, action, reward, new_state, done)


	@tf.function
	def choose_action(self, observation, evaluate=False):
		observation = tf.expand_dims(observation, axis=0)
		means = self.actor(observation)
		actions = tf.random.normal(shape=[self.n_actions], mean=means, stddev=self.noise)
		actions = tf.clip_by_value(actions, self.min_action, self.max_action)
		return actions[0]

	
	def learn(self):
		if self.memory.mem_cntr < self.batch_size:
			return 0, 0

		state, new_state, action, reward, done = self.memory.sample_buffer(self.batch_size)
		state = tf.cast(state, tf.float32)
		reward = tf.reshape(reward, (-1, 1))

		Q_ = self.target_critic(new_state, self.target_actor(new_state))
		yi = reward + self.gamma * Q_ 
		self.update_actor(state)
		self.update_critic(state, action,yi)
		
		actorLoss = -tf.reduce_mean(self.critic(state, self.max_action * self.actor(state)))
		criticLoss = tf.reduce_mean(tf.math.square(yi - self.critic(state, action)))
		self.update_network_parameters()
		return actorLoss, criticLoss


	@tf.function
	def update_actor(self,state):
		with tf.GradientTape(persistent=False) as tape:
			mu = self.max_action * self.actor(state)
			
			Q = self.critic(state, mu)
			actorLoss = -tf.reduce_mean(Q)

			Grad = tape.gradient(actorLoss, self.actor.trainable_variables)
		self.actor.optimizer.apply_gradients(zip(Grad, self.actor.trainable_variables))
		return actorLoss
	
	def update_critic(self, state, action, yi):
		self.critic.fit(tf.concat([state, action],axis=1), yi, verbose=0)
		

if __name__ == "__main__":
	
	env = gym.make("Pendulum-v0")
	
	ALPHA = 1e-4
	BETA = 1e-3
	GAMMA = 0.99
	TAU = 0.005
	BUFFER_SIZE = 1000000
	NOISE = 0.1
	BATCH_SIZE = 64
	OBS_DIMS = env.observation_space.shape[0]
	N_ACTIONS = env.action_space.shape[0]

	agent = Agent(OBS_DIMS, N_ACTIONS, env, BUFFER_SIZE, BATCH_SIZE, ALPHA, BETA, GAMMA, TAU, NOISE)


	wandb.init(project="Pendulum")
	wandb.config.alpha= ALPHA
	wandb.config.beta = BETA
	wandb.config.gamma = GAMMA
	wandb.config.tau = TAU
	wandb.config.noise = 0.0
	wandb.config.batch_size = BATCH_SIZE

	n_games = 500

	best_score = env.reward_range[0]

	score_history = []
	mean_score = []
	
	video_recorder = VideoRecorder(env, path="Results/DDPG.mp4")

	with tqdm.trange(n_games) as t:

		for i in t:
			observation = env.reset()
			done = False
			score = 0
			episode_steps = 0	
			while True:
				action = agent.choose_action(observation, False).numpy()
				observation_, reward, done, info = env.step(action)
				score += reward
				agent.remember(observation, action, reward, observation_, done)
				ActorLoss, CriticLoss = agent.learn()
				episode_steps+=1
				observation = observation_
				if done:
					score_history.append(score)
					mean_score.append(np.mean(score_history[-100: ]))

					score = 0
						

					done = False
					observation = env.reset()
						
					t.set_postfix_str(f" Episode : {i}, score: {np.mean(score_history[-100:])}")
					break
					
					

			wandb.log({"Average Reward":mean_score[-1], "Actor Loss":ActorLoss, "Critic Loss": CriticLoss, "Scores":score_history[-1]})
		
			
		
	observation = env.reset()
	for _ in range(200):
		env.render()
		video_recorder.capture_frame()
		action = agent.choose_action(observation, False).numpy()
		observation, reward, done, info = env.step(action)
	env.close()
	video_recorder.close()
	video_recorder.enabled = False

	plt.plot(mean_score, label=f"Mean Scores{t}")
	plt.plot(score_history, label=f"All Scores{t}")
		
	plt.show()
	plt.legend()