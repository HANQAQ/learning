import os
os.add_dll_directory(os.environ['minGwPath'])

from build import flyBall as env

# init environment
env.reset()

#initiate store lists
states = []
actions = []
rewards = []

# run for 3 episodes
episodes = 3
for episode in range(episodes):
    states = []
    actions = []
    rewards = []
    env.reset()
    while not env.done():
        #state:[t, y, vy, ay, target_t, target_y, target_vy]
        state = env.get_real_state()
        action = 0
        reward = env.reward()

        env.step(action)
        states.append(state)
        actions.append(action)
        rewards.append(reward)

        print(f"episode: {episode} ,state: {state[:4]}, action: {action}, reward: {reward}")

    print(f"episode: {episode}, Total reward: {sum(rewards)}")

