import gymnasium as gym
import pygame
import torch
from deep_q_learning import Dqn

brain = Dqn(8,4,0.9)

env = gym.make('CartPole-v1')
env = gym.make("LunarLander-v2", render_mode='human') #, render_mode='human'
observation, info = env.reset()
reward = 0
brain.load()


action = brain.update(observation, reward)
for _ in range(200000):
    
    observation, reward, terminated, truncated, info = env.step(action)
    action = brain.select_action(torch.tensor(observation).float().unsqueeze(0))
    action = action.item()
    #action = brain.update(observation, reward)
    if reward >= 97:
        print("recompensa foi 100 aproximadamente ")
        print(reward)

    if terminated or truncated:
        observation, info = env.reset()
        print(reward)

#brain.save()
print("brain saved")

env.close()