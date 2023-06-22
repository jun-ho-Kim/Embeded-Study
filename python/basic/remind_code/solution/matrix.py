# %%
import numpy as np

# %%
a = [1,2,3]
b = [4,5,6]
print(a, type(a))
print(b, type(b))
print(a+b, type(a+b))

# %%
a = np.array([1,2,3])
b = np.array([4,5,6])
print('a=',a, type(a))
print('b=',b, type(b))
print('a+b=',a+b, type(a+b))
# %%
c = b#얕은 복사...주소값만 공유
print('c=',c, type(c))
# %%
b[1] = 100
print('b=',b, type(b))
print('c=',c, type(c))#?? c == b
# %%
# %%
b[1] = 5  #re-init as 5
c = b.copy()   #깊은 복사...모든 데이터 새로운 공간에 생성
print('c=',c, type(c))
# %%
b[1] = 100
print('b=',b, type(b))
print('c=',c, type(c))#?? c == b













# %%
a = [x for x in range(10)]
print('a=',a, type(a))
# %%
a = np.arange(12, dtype=np.int64)
print('a=',a, type(a), 'shape=', a.shape)
# %%
# transform shape as reshape(m,n)
a = a.reshape(3,4)
print('a=',a, type(a), 'shape=', a.shape)
a = a.reshape(4,3)
print('a=',a, type(a), 'shape=', a.shape)
a = a.reshape(2,3,2)
print('a=',a, type(a), 'shape=', a.shape)
# %%
#linear algebra
#maxrix 곱 = ( mxn )dot(nxk) = mxk


# %%
#zero matrix
a =  np.zeros(10)
print('a=',a, type(a), 'shape=', a.shape)
a =  np.zeros((2,5))
print('a=',a, type(a), 'shape=', a.shape)
#ones matrix
a =  np.ones((2,5))
print('a=',a, type(a), 'shape=', a.shape)

# %%
#matrix arith
a = np.array([1,2,3])
b = np.array([4,5,6])
print('a=',a, type(a))
print('b=',b, type(b))
print('a+b=',a+b, type(a+b))
print('a-b=',a-b, type(a-b))
print('3*a-b=',3*a-b, type(3*a-b))

a = np.array([1,2,3])
b = np.exp(a)
print('b=',b, type(b))

v = np.array(
    [
        [1,2,3],
        [4,5,6]
    ])
print('v=',v, type(v), 'shape=', v.shape)
w = np.array(
    [
        [1,1],
        [2,2],
        [3,3]
    ]
    )
print('w=',w, type(w), 'shape=', w.shape)
z = v.dot(w)
print('z=',z, type(z), 'shape=', z.shape)
# %%
#Quize
#matrix x을 이용하여 구구단 2~5을 구하시오
# 단 : 2~5, Step : 1~9   //// #     4x9  9x1  = 4x1
#matrix .dot()을 이용하여 구구단 2~5 각 단의 총합을 구하시오
#  2단 총합 = ?
#  3단 총합 = ?
#  4단 총합 = ?
#  5단 총합 = ?
#
#hint
#
import numpy as np
D = np.ones((4,9))
print('D = ', D, D.shape)
D[0] = D[0]*2
D[1] = D[1]*3
D[2] = D[2]*4
D[3] = D[3]*5
print('D = ', D, D.shape)
S = np.arange(1,10)
print('S = ', S, S.shape)

Z = D.dot(S)
print(Z, Z.shape)
G = D*S
D[0] = D[0]*S
D[1] = D[1]*S
D[2] = D[2]*S
D[3] = D[3]*S
print('D = ', D, D.shape)


for d in range(0,len(G),1):
    print('mmmmmmmmmmmmm'*5)
    for n in range(0,len(G[d]),1):
        print(int(G[d][0]),'*',n+1,'=',G[d][n])
    print('============='*5)
    print('sum = ',Z[d])
    
# %%
# %%
import numpy as np
D = np.ones((4,9))
idx=0
for k in range(2,6,1):
    D[idx]=D[idx]*k
    idx += 1
S = np.arange(1,10)
print('D = ',D, D.shape)
print('S = ',S, S.shape)
G = D*S
print('D*S = ',G)
Z = D.dot(S)
print(Z, Z.shape)

for d in range(0,len(G),1):
    print('mmmmmmmmmmmmm'*5)
    for n in range(0,len(G[d]),1):
        print(int(G[d][0]),'*',n+1,'=',G[d][n])
    print('============='*5)
    print('sum = ',Z[d])
# %%
A = np.array([1,3])
B = np.array([4,2])
'''
(1 3) ( 4  )   =  1*4 + 3*2 = 10
        2
'''
C = A.dot(B)
print('A=', A, A.shape)
print('B=', B, B.shape)
print('C=', C, C.shape)
# %%
