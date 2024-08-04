import gym
import numpy as np
import torch
from ddpg import Actor
import pygame

env = gym.make('Pendulum-v1', render_mode='rgb_array')
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
STATE_DIM = env.observation_space.shape[0]
ACTION_DIM = env.action_space.shape[0]

#load the actor network
actor = Actor(STATE_DIM, ACTION_DIM).to(device)
state_dict = torch.load('actor.pth')
actor.load_state_dict(state_dict.state_dict())

#initialize pygame
pygame.init()
screen = pygame.display.set_mode((400, 400))
pygame.display.set_caption('Pendulum-v1')
clock = pygame.time.Clock()

#run the game
EPISODES = 10
MAX_STEPS = 200
for ep in range(EPISODES):
    state, _ = env.reset()
    episode_reward = 0

    for step in range(MAX_STEPS):
        frame = env.render()
        frame = pygame.surfarray.make_surface(np.rot90(frame))
        frame = pygame.transform.scale(frame, (400, 400))
        pygame.display.flip()
        screen.blit(frame, (0, 0))
        pygame.display.update()
        clock.tick(60)

        state = torch.FloatTensor(state).to(device)
        action = actor(state).detach().cpu().numpy()
        next_state, reward, done, _, _ = env.step(action)
        episode_reward += reward

        if done:
            break

        state = next_state

    print(f'Episode: {ep}, Reward: {episode_reward}')