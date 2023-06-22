# %%
import numpy as np

def val_show(v,name):
    print(name, ' = ', v, type(v), v.shape)    

# %%
a = np.array([1,3])#vector
b = np.array([2,1])#vector
c = a+b
val_show(a, 'a')
val_show(b, 'b')
val_show(c, 'c')
# %%
#transpose ...전치
a = np.array(
[
[1,2],
[3,4]
]
)
val_show(a, 'a')
a = a.T
val_show(a, 'a')
# %%
a = a.T
a = 100*a
val_show(a, 'a')
# %%
a = np.array([1,3])#vector
b = np.array([2,1])#vector
#1*2 + 3*1
c = a.dot(b)
val_show(c, 'c')
# %%
#벡터의 크기
b = np.array([2,1])
scale = np.linalg.norm(b)
print(scale)


# %%
