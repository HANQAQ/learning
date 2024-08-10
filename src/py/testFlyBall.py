import os
os.add_dll_directory(os.environ['minGwPath'])

from build import flyBall as env
from ddpg import Actor
import numpy as np
import torch
import matplotlib.pyplot as plt

# init environment
env.reset()

#load actor
model_path = os.environ['MODEL_PATH']
actor = Actor(7, 1)
actor.load_state_dict(torch.load(os.path.join(model_path, '2000actor.pth')))


#initiate store lists
states = []
actions = []
rewards = []
times = []

# run for 3 episodes
episodes = 1
for episode in range(episodes):
    states = []
    actions = []
    rewards = []
    env.reset()
    while not env.done():
        #state:[t, y, vy, ay, target_t, target_y, target_vy]
        state = env.get_real_state()
        state_norm = env.state()
        action = actor(torch.FloatTensor(state_norm)).detach().numpy()
        reward = env.reward()

        env.step(12 * action)
        states.append(state)
        actions.append(action)
        rewards.append(reward)

        print(f"episode: {episode} ,state: {state[:4]}, action: {state}, reward: {reward}")

    print(f"episode: {episode}, Total reward: {sum(rewards)}")

states = np.array(states)
actions = np.array(actions)

#plot curves: y-t, vy-t, acion-t
fig, axs = plt.subplots(3,1)
axs[0].plot(states[:,0], states[:,1], label='y-t')
axs[0].set_xlabel('t')
axs[0].set_ylabel('y')
axs[0].legend()

axs[1].plot(states[:,0], states[:,2], label='vy-t')
axs[1].set_xlabel('t')
axs[1].set_ylabel('vy')
axs[1].legend()

axs[2].plot(states[:,0], actions, label='action-t')
axs[2].set_xlabel('t')
axs[2].set_ylabel('action')
axs[2].legend()

plt.show()



