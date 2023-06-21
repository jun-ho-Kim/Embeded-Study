# %%
import numpy as np

a = [1,2,3]
b = [4,5,6]
print(a, type(a)) # list
print(b, type(b))
# list는 + 시 append가 된다.
print(a+b, type(a+b)) # [1, 2, 3, 4, 5, 6]

# %%
a = np.array([1,2,3])
b = np.array([4,5,6])
print(a, type(a))
print(b, type(b))
# ndarray는 + 시 각 위치에 +를 해준다.
#numpy.ndarray - n 차원에 배열을 담을 수 있다.
print(a+b, type(a+b)) # [5 7 9]

# %%
c = b # 앝은 복사 ... 주소 값만 공유
b[1] = 100
print(b , type(b))  # [4 100 6]
print(c, type(c))   # [4 100 6]

# %%

c = b.copy()
# 깊은 복사 ... 모든 데이터 새로운 공간에 생성
b[1] = 5
print(b , type(b))  # [4 5 6]
print(c, type(c))   # [4 100 6]

# %%
a = [x for x in range(10)]
print('a=', a, type(a))

# %%
a = np.arange(10, dtype=np.int64)
print('a=', a, type(a))
# %%
#transform shape as reshape(m,n)
a = a.reshape(2,5)
print('a=', a, type(a)) # a = [[0 1 2 3 4] [5 6 7 8 9]] <class 'numpy.ndarray'>
print('a=', a, type(a), 'shape=', a.shape) # ...shape = (2,5)


a = a.reshape(5,2)
print('a=', a, type(a), 'shape=', a.shape)
# a= [[0 1] [2 3] [4 5] [6 7] [8 9]] <class 'numpy.ndarray'> shape=(5,2)
a = a.reshape(5,2)
print('a=', a, type(a), 'shape=', a.shape)
# %%
# linear algebra
b = np.arange(15, dtype=np.int64)
print('b=', b, type(a), 'shape=', b.shape)
b = b.reshape(5,3)
print('b=', b, type(a), 'shape=', b.shape)

#matrix 곱 = (mxn)dot(nxk) = mxk

# %%
#zero matrix
a = np.zeros(10)
print('a=', a, type(a), 'shape=', a.shape)
a = np.zeros((2,5))


# %%
#matrix arith

a = np.array([1, 2, 3])
b = np.array([4, 5, 6])
print('a=', type(a))
print('b=', type(b))
print('a+b=', a+b, type(a+b))
print('a-b=', a-b, type(a-b))
print('3*a=', 3*a-b, type(3*a))
 
a = np.array([1, 2,3])
b = np.exp(a)
print('b=', b, type(b))

v = np.array(
    [
        [1,2,3], 
        [4,5,6]
    ])
print('v=', v, type(v), 'shape=', v.shape)

w = np.array(
    [
        [1,2],
        [2,2],
        [3,3]
    ]
)
print('w=', w, type(w), 'shape=', w.shape)
z = v.dot(w)
print('z=', z, type(z), 'shape=', z.shape)

# %%
# Quize
# matrix .dot()을 이용하여 
# 구구단을 구하시오
# 단: 2~5, step : 1~9
# 4x9   9x1 = 4x1

D= np.ones((4, 9))
print('D = ', D, D.shape)
D[0] = D[0]*2
D[1] = D[1]*3
D[2] = D[2]*4
D[3] = D[3]*4
S= np.arange(1, 10)
print("D =", D)
print("S =", S)

G = D*S
print("D * S = ", G)
Z=D.dot(S)
print(Z, Z.shape)

D[0] = D[0]*S
D[1] = D[1]*S
D[2] = D[2]*S
D[3] = D[3]*S
print("D =", D, D.shape)


# %%
idx = 0
D= np.ones((8, 9))
for k in range(2, 10, 1):
    D[idx] = k
    idx += 1
S= np.arange(1, 10)
print("D =", D)
print("S =", S)
G = D * S
print("D*S=", G)
Z = D.dot(S)
print("Z is = ", Z ,Z.shape)

#print(Z, Z.shape)

#%%
dan = np.array(
    [
        [2,2,2,2,2,2,2,2,2],
        [3,3,3,3,3,3,3,3,3],
        [4,4,4,4,4,4,4,4,4],
        [5,5,5,5,5,5,5,5,5],
        [6,6,6,6,6,6,6,6,6],
        [7,7,7,7,7,7,7,7,7],
        [8,8,8,8,8,8,8,8,8],
        [9,9,9,9,9,9,9,9,9],
    ]
)
step = np.array(
    [
        [1],
        [2],
        [3],
        [4],
        [5],
        [6],
        [7],
        [8],
        [9]        
    ]
)
result = dan.dot(step)
print('result=', result, type(result), 'shape=', result.shape)

for x in range(2, 10, 1):
    print(x,'단의 총합 =', result[x-2])

# %%


# %%
# Matrix 더 이해하기

A = np.array([1, 3])
B = np.array([4,2])
'''
(1 3) (4   ) = 1 * 4 + 3 * 2 = 10
        2
#   )
'''
C = A.dot(B)

print('A=', A, A.shape)
print('B=', B, B.shape)
print('C=', C, C.shape)

# %%
