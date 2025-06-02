# A 5 uC charge is located at (0, 0), sample positions of a 1 uC charge of mass 1 kg initially located at (1, 0)
import numpy as np
# [charge, mass, x pos, y pos]
K = 8.99E9
MAX_TIMESTEPS = 1000    #in ms
NUM_TIMESTEPS = 20
SPATIAL_DIM = 2

timesteps = np.linspace(0, MAX_TIMESTEPS, NUM_TIMESTEPS)
timesteps /= 1000
fiveC = np.array([5E-6, 0, 0, 0], dtype=np.float32)     # [charge, mass, x pos, y pos]
target = np.array([1E-6, 1, 1, 0], dtype=np.float32)    # [charge, mass, x pos, y pos]

positions = np.zeros((SPATIAL_DIM, NUM_TIMESTEPS), dtype=np.float32)

acceleration = np.zeros((SPATIAL_DIM, NUM_TIMESTEPS))
acceleration[0] += K * fiveC[0] * target[0] / ( np.linalg.norm([1, 0])**2 * target[1] )
positions[0] += np.array([1, 0], dtype=np.float32)[0] + 0.5*acceleration[0]*(timesteps**2)
positions[1] += np.array([1, 0], dtype=np.float32)[1] + 0.5*acceleration[1]*(timesteps**2)

print(positions[0])




