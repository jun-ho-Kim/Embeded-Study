# %%
import numpy as np
import matplotlib.pyplot as plt

#pip install numpy
#pip install matplotlib


# %%
#data
np.random.seed(1)
x = np.arange(10)#0,1,2,3,4,9
y = np.random.rand(10)# 0,4,2,1,4,2,2
rng = np.random.default_rng()
y = rng.normal(size=10)
#그래프 출력
plt.figure(figsize=(3,2))
plt.plot(x,y) #plot function ... input (x - axis,y - axis)
plt.show()


# %%
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 2 * np.pi, 200)
y = np.sin(x)

fig, ax = plt.subplots()
ax.plot(x, y)
plt.show()
# %%
