import numpy as np
import scipy as sp

A = np.array([2, 1, 3,1, 2, 3,3, 2, 1], dtype=float)
B = np.array([0, 1,2, 0], dtype=float)

print(sp.signal.convolve(A, B))
