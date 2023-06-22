# %%
import numpy as np
import matplotlib.pyplot as plt

def f(w0, w1):
    return w0**2 + 2*w0*w1 + 3

def df_dw0(w0, w1):
    return 2*w0 + 2 * w1

def df_dw1(w0, w1):
    return 2 * w0 + 0 * w1

w_range = 2
dw = 0.25

w0 = np.arange(-w_range, w_range+dw, dw) # line space를 통해 만들어 줄 수 있음
w1 = np.arange(-w_range, w_range + dw, dw)
wn = w0.shape[0]

ww0, ww1 = np.meshgrid(w0, w1)

print("w0 = ", w0)
print("w1 = ", w1)

#print("ww0 = ", ww0)
#print("ww1 = ", ww1)

ff= np.zeros((len(w0), len(w1)))
dff_dw0 = np.zeros((len(w0), len(w1)))
dff_dw1 = np.zeros((len(w0), len(w1)))
for i0 in range(wn):
    for i1 in range(wn):
        ff[i1, i0] = f(w0[i0], w1[i1])
        dff_dw0[i1, i0] = df_dw0(w0[i0], w1[i1])
        dff_dw1[i1, i0] = df_dw1(w0[i0], w1[i1])

plt.figure(figsize=(9, 4))
plt.subplots_adjust(wspace=0.3)
plt.subplot(1, 2, 1)

cont = plt.contour(ww0, ww1, ff, 10, colors='k')
cont.clabel(fmt='%2.0f', fontsize=8)
plt.xticks(range(-w_range, w_range+1, 1))
plt.yticks(range(-w_range, w_range+1, 1))

# 그래프 사이에 간격이 생김
plt.xlim(-w_range - 0.5, w_range + .5)
plt.ylim(-w_range - .5, w_range + .5)

plt.xlabel('$w_0$', fontsize=14)
plt.ylabel('$w_1$', fontsize=14)

plt.show()


plt.subplot(1, 2, 2)
plt.quiver(ww0, ww1, dff_dw0, dff_dw1)
plt.xlabel('$w_0$', fontsize=14)
plt.ylabel('$w_1$', fontsize=14)
plt.xticks(range(-w_range, w_range+1, 1))
plt.yticks(range(-w_range, w_range+1, 1))
plt.xlim(-w_range - 0.5, w_range + .5)
plt.ylim(-w_range - .5, w_range + .5)
plt.show()

ax = plt.subplot(1, 1, 1, projection='3d')
y = f(ww0, ww1)
ax.plot_surface(ww0,ww1, y, rstride = 1, cstride =1, alpha = 0.3,
                color=  'blue', edgecolor= 'black')
plt.xlabel('$w_0$', fontsize=14)
plt.ylabel('$w_1$', fontsize=14)
plt.xticks(range(-w_range, w_range+1, 1))
plt.yticks(range(-w_range, w_range+1, 1))
plt.xlim(-w_range - 0.5, w_range + .5)
plt.ylim(-w_range - .5, w_range + .5)




# %%
import numpy as np
import matplotlib.pyplot as plt
def f(w0, w1):
    return w0**2 + 2*w0*w1 + 3 #  x^2 + 2xy + 3
def df_dw0(w0, w1):
    return 2*w0 + 2*w1
def df_dw1(w0, w1):
    return 2*w0

w_range = 10
dw = 1
w0 = np.arange(-w_range, w_range+dw, dw)
w1 = np.ones(len(w0))
w1 *= -1
w0 = np.linspace(-w_range, w_range, 50)

planes = [-1,1]#w0 : -1, 1.....w1 : -1,1

figIndex = 1
plt.figure(figsize=(7,7))
plt.subplots_adjust(wspace=0.5, hspace=0.5)

for i, p in enumerate(planes):
    w1 = np.full(w0.shape, planes[i]) #-1, 1
    plt.subplot(2,2, figIndex)

    labelName = f'$w_1={planes[i]}$'
    plt.plot(w0, f(w0,w1), 'black', linewidth=3, label=labelName)
    plt.plot(w0, df_dw0(w0,w1), 'cornflowerblue', linewidth = 3, label = '$dw_0$')
    plt.xlabel('$w_0$')
    plt.ylabel('$y$')
    plt.ylim(-10,10)
    plt.xlim(-2,2)
    plt.grid(True)
    plt.legend(loc='lower right')
    figIndex +=1

w1 = np.linspace(-w_range, w_range, 50)
for i, p in enumerate(planes):
    w0 = np.full(w1.shape, planes[i]) #-1, 1
    plt.subplot(2,2, figIndex)

    labelName = f'$w_0={planes[i]}$'
    plt.plot(w1, f(w0,w1), 'black', linewidth=3, label=labelName)
    plt.plot(w1, df_dw1(w0,w1), 'cornflowerblue', linewidth = 3, label = '$dw_1$')
    plt.xlabel('$w_1$')
    plt.ylabel('$y$')
    plt.ylim(-10,10)
    plt.xlim(-2,2)
    plt.grid(True)
    plt.legend(loc='lower right')
    figIndex +=1



'''
w_range = 10
dw = 1
w0 = np.arange(-w_range, w_range+dw, dw)
w1 = np.ones(len(w0))
w1*= -1

w0 = np.linspace(-w_range, w_range, 50)
w1 = np.full(w0.shape, -1)

planes = [-1, 1] # w0 : -1, 1.....w1 : -1, 1

figIndex = 1
plt.figure(figsize=(7,7))
plt.subplots_adjust(wspace=0.5, hspace=0.5)

for i, p in enumerate(planes):
    w1 = np.full(w0.shape, planes[i]) # -1, 1
    plt.subplot(2, 2, figIndex)

    labelName = '$w_1={planes[i]}$'
    plt.plot(w0, f(w0, w1), 'black', linewidth=3, label=labelName)
    plt.plot(w0, df_dw0(w0, w1), 'conflowerblue', linewidth = 3, label = '$$')
    plt.title('$w_0')

print("w0 = ", w0)
print("w1 = ", w1)

print('df = ', f(w0, w1))
print('df_dw0 = ', df_dw0(w0, w1))
print('df_dw1 = ', df_dw1(w0, w1))

plt.figure(figsize=(5, 5))
plt.plot(w0, f(w0, w1), 'black', linewidth='3')
plt.plot(w0, df_dw0(w0, w1), 'cornflowerblue', linewidth='3')
plt.xlabel('$w_0$')
plt.xlabel('$y$')
plt.ylim(-10, 10)
plt.ylim(-2, 2)
plt.legend(loc='lower right')
figIndex += 1
'''
# %%

#역행렬
import numpy as np
A = np.array(
    [
        [1,2],
        [3,4]
    ]
)

A_Inv = np.linalg.inv(A)
print('A_Inv = ', A_Inv)

I = A*A_Inv
print('I =', I)


I = A_Inv.dot(A)
I = np.round(I, 2)
print('I =', I)

I = A.dot(A_Inv)
I = np.round(I, 2)
print('I =', I)

#I = A*A_Inv

I = np.identity(3) # 단위 행렬
print('I =', I)

# %%

#연립 방정식 문제
# 2x - y = 0
# x + y = 3
# x, y는 무엇일까요?

A = np.array(
    [
        [2, -1],
        [1, 1]
    ]   
)
Y = np.array(
    [0, 3]
)



# Y = A * X
# Y * A_Inv = A*A_Inv * X
# Y * A_Inv = I*X = X

A_Inv = np.linalg.inv(A)
print('A_Inv is ', A_Inv)
X = A_Inv.dot(Y)
print("result is ", X)



# %%
## Trans

# X로 한 칸 이동
Trans = np.array(
    [
        [1, 0, 1],
        [0, 1, 0],
        [0, 0, 1]
    ]
)
#[1 1 1] [2 1 1]

Trans = np.array(
    [
        [0.12, 0.1, 1],
        [0.1, 0.12, 1],
        [0, 0, 1]
    ]
)
#[1 1 1] [1.22 1.22 1.  ]


A = np.array([1 , 1, 1])
B = Trans.dot(A)
print(A, B)
# %%
