# %%
import numpy as np
import matplotlib.pyplot as plt

# %%
#data
np.random.seed(1)
x = np.arange(10)
y = np.random.rand(10)
print('y is', y)
rng = np.random.default_rng()
y = rng.normal(size=10)
#그래프 출력

print(x)
print(y)
print(rng)
plt.figure(figsize=(3,2))
plt.plot(x,y)
plt.show()

# %%
