# %%
import matplotlib.pyplot as plt
import numpy as np
from PIL import Image

def val_show(v, name):
    print(name, ' = ', v, type(v), v.shape)

# %%
# 그래프 출력
np.random.seed(1)
x = np.arange(10) #1, 2, 3, 4, .... 10
y = np.random.rand(10) #random

val_show(x, 'x')
val_show(y, 'y')

plt.plot(x,y)
plt.show()

#print('x = ', x, type(x), x.shape)
#print('y = ', y, type(y), y.shape)
# %%
# 곡선 출1력
# y = f(x)
# f(x) = a*x^2 + b*x + c

def f(x): # 3차 다항식
    y = (x-2)*x*(x+2)
    return y

def f(x, w): # 3차 다항식
    y = (x-w)*x*(x+w)
    return y

#x = np.arange(10) #1, 2, 3, 4, .... 10
#x = np.arange(-3, 3, 0.1)
x = np.linspace(-3, 3, 50) # -3~3 까지의 5개의 샘플링을 가짐
#y = f(x) #random

y1 = f(x, 2)
y2 = f(x, 1)

val_show(x, 'x')
val_show(y, 'y')

plt.plot(x,y, color='yellow', label = '$f1$')
plt.plot(x,y1, color='blue', label = '$w=2$')
plt.plot(x,y2, color='orange', label = '$w=1$')
plt.plot(x,f(x, 0), color='red', label = '$w=0$')
plt.legend(loc='upper left')
plt.ylim(-15, 15)
plt.xlim(-3, 3)
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.show()

# %%
def f(x, w): # 3차 다항식
    y = (x-w)*x*(x+w)
    return y

plt.figure(figsize=(10, 3))
plt.subplots_adjust(wspace=0.5, hspace=0.5)
for i in range(6):
    plt.subplot(2, 3, i+1)
    plt.title(i+1)
    plt.plot(x, f(x, 1), 'k')
    plt.ylim(-20, 20)
    plt.grid(True)
plt.show()

# %%
# 구구단을 subplot으로 출력하시오
def f(dan, step):
    '''
    arr = []
    for step in (1,10, 1):
        result = dan*step
        arr.append(result)

    print("arr is ", arr)
    '''
    y = dan*step
    return y

x = np.arange(2, 10)
plt.figure(figsize=(10, 10))
plt.subplots_adjust(wspace=0.5, hspace=0.5)

for i in range(2, 10):
    plt.subplot(3,3, i-1)
    #name = i + "단"
    plt.title(i)
    plt.plot(x, f(x, i),'k')
    plt.ylim(0, 100)
    plt.grid(True)
plt.show()


# %%
# 면 출력

def f3(x0, x1):
    r = 2*x0**2 + x1**2
    ans = r*np.exp(-r)
    return ans

xn = 9
x0 = np.linspace(-2, 2, xn)
x1 = np.linspace(-2, 2, xn)
y = np.zeros((len(x0), len(x1)))

val_show(x0, 'x0')
val_show(x1, 'x1')
val_show(y, 'y')

for i0 in range(xn):
    for i1 in range(xn):
        y[i1, i0] = f3(x0[i0], x1[i1])
        y = np.round(y ,1)
        val_show(y, 'y')
plt.figure(figsize=(3.5, 3))
plt.gray()
plt.pcolor(y)
plt.colorbar()
plt.show()

# %%

from mpl_toolkits.mplot3d import axes3d
xx0, xx1 = np.meshgrid(x0, x1)
plt.figure(figsize=(6,5))
ax = plt.subplot(1, 1, 1, projection='3d')
ax.plot_surface(xx0, xx1, y, rstride = 1, cstride =1, alpha = 0.3,
                color=  'blue', edgecolor= 'black')
ax.set_zticks((0, 0.2))
ax.view_init(75, -15)
plt.show()

# %%

xn = 10
x0 = np.linspace(-2, 2, xn)
x1 = np.linspace(-2, 2, xn)
y = np.zeros(len(x0), len(x1))
for i0 in range(xn):
    for i1 in range(xn):
        y[i1, i0] = f3(x0[i0], x1[i1])

xx0, xx1 = np.meshgrid(x0, x1)
plt.figure(figsize=(5,5))
cont = plt.contour(xx0, xx1, y, 5, colors='black')
cont.clabel(fmt='%3.2f', fontsize=8)
plt.xlabel('$x_0$', fontsize=14)
plt.xlabel('$x_1', fontsize=14)

# %%
