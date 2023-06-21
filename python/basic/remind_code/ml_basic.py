# %%
import numpy as np

def val_show(v, name):
    print(name, ' = ', v, type(v), v.shape)

a = np.array([1,3]) # vector
b = np.array([2,1]) # vector
val_show(a, 'a')
val_show(b, 'b')

# %%
#transpose … 전치
a = np.array(
    [
        [1, 2],
        [3,4]
    ]
)
val_show(a, 'a') #a  =  [[1 2] [3 4]]
a = a.T # #transpose … 전치
#a = 10 *a
val_show(a, 'a') # a  =  [[1 3] [2 4]]

# %%

# 벡터 내적
a = np.array([1,3])
b = np.array([2,1])
c = a.dot(b) # 벡터 내적: 
val_show(c, 'c')  

# %%
# 벡터의 크기
b = np.array([2,1])
scale = np.linalg.norm(b)
print(scale)