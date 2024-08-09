 # Project: CartPole DDPG   
import torch
import gym
import numpy as np
from ddpg import DDPGAgent
import os


env = gym.make('Pendulum-v1', render_mode='rgb_array')
STATE_DIM = env.observation_space.shape[0]
ACTION_DIM = env.action_space.shape[0]


agent = DDPGAgent(STATE_DIM, ACTION_DIM)

#hyperparameters
MAX_EPISODES = 200
MAX_STEPS = 200
batch_size = 64

for ep in range(MAX_EPISODES):
    state, _ = env.reset()
    episode_reward = 0

    for step in range(MAX_STEPS):
        action = agent.get_action(state) + np.random.normal(0, 0.1, ACTION_DIM)
        next_state, reward, done, _, _ = env.step(2 * action)
        agent.memory.push(state, action, reward, next_state, done)
        episode_reward += reward

        if len(agent.memory) > batch_size:
            agent.update(batch_size=batch_size)

        if done:
            break

        state = next_state

    print(f'Episode: {ep}, Reward: {episode_reward}')

env.close()
save_dir = 'F:\\vscode\\somelearning'
os.makedirs(save_dir, exist_ok=True)
torch.save(agent.actor, os.path.join(save_dir, 'actor.pth'))
torch.save(agent.critic, os.path.join(save_dir, 'critic.pth'))
 























