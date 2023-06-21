# %%
# 변수 ...


a = 10
print(a, type(a))
a=0.123
print(a, type(a))
a = 'hello world, python'
print(a, type(a))


# C/C++ struct/class ... arr ...


struct _AA
{
    int a= 10;
    int b= 20;
}
# 파이썬에서는 struct에 들어가는 자료형은 배열에 들어간다.




# %%

#python
#list ... read/write/add/remove
print('----'*10)
a = 10
b = 20
v = [a, b]
print(v, type(v))
v[0] #a
print(v[0], type(v[0]))
v[1] #b
print(v[1], type(v[1]))
v[1] = 300
print(v[1], type(v[1]))

#tuple ... read only ... packed
#데이터가 변경이 안되거나 메모리에 오염이 안되어야 할 때 사용
a = (10,20,30) #transfer
print(a,type(a))
print(a[0],type(a[0]))
print(a[1],type(a[1]))
print(a[2],type(a[2]))
# a[2] = 100 # error

#dict ... db/add/remove/**search
#데이터를 찾기 편한 자료구조
value = 'value'
a = {'key1': value+'1'}
a = {'key2': value+'2'}
a = {'key3': value+'3'}
a = {'key4': value+'4'}
a = {'key5': value+'5'}
print(a, type(a))
#  key        data
a['key2'] = 'value2'
a['key3'] = [1,2,3,4,5]
print(a, type(a))

#Point**... vector<vector<Point>> contours
#디렉터리는 이중벡터를 가지고 있기 때문에 key와 value를 가지고 데이터를 관리할 수 있다.
# %%

#string
str1 = 'hello'
str2 = 'world'
msg = str1 + str2
msg = '%s %s' % (str1, str2) # 가운데 % 기준으로 왼쪽은 
#(str1, str2)은 튜플로 사용된다.
print(msg)
msg = f'{str1} {str2}'
print(msg)

print("hello wolrd2");

# %%

#if ... for
for x in range(1, 10+1, 1):
    if x%2 == 0:
        msg = f'even {x}'
    else:
        msg = f'odd {x}'
    print(msg)
1# %%

# %%

#이중 for문 : 전체 구구단표

for i in range(2,10, 1):
    msg = ''
    for j in range(1,10, 1):
        msg += f'{j:d} x {i:d} = {i*j:2d}\t'
    print(msg)
    msg += '\n'

        


# %%
