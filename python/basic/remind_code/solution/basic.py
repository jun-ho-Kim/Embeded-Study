# %%

# 변수 ....
'''
c/c++ 
int .. type    변수   =  데이타
code -> 해석 -> compiler -> 타입 지정 ... memory 관리
#int va = 10;
python
               변수   = 데이타
'''
a = 10 # =, type init
print(a, type(a))
a = 0.123
print(a, type(a))
a = 'hello world, python'
print(a, type(a))

# c/c++ struct/class ... array ... 
'''
struct _AA
{
    int a = 10;
    int b = 20;
}
_AA aa;
aa.a
aa.b

'''
#python
#list ... read/write/add/remove
print('----'*10)
a = 10
b = 20
v = [a,b]
print(v, type(v))
v[0]#a
print(v[0], type(v[0]))
v[1]#b
print(v[1], type(v[1]))
v[1] = 300
print(v[1], type(v[1]))
print('----'*10)
#tuple ... read only ... packed
a = (10,20,30) #transfer
print(a, type(a))
print(a[0], type(a[0]))
print(a[1], type(a[1]))
print(a[2], type(a[2]))
#a[2] = 100
#dict ... db/add/remove/search
value = 'value'
a = {'key1' : value+'1'}
#a = {'key2' : value+'2'}
#a = {'key3' : value+'3'}
#a = {'key4' : value+'4'}
#a = {'key5' : value+'5'}
print(a, type(a))
#   key       data
a['key1'] = 1
a['key2'] = 'value2'
a['key3'] = [1,2,3,4,5]
print(a, type(a))

#Point**... vector<vector<Point>> contours
# %%
#string
str1 = 'hello'
str2 = 'world'
msg = str1 + str2
print(msg)
msg = '%s %s' % (str1, str2)
print(msg)
msg = f'{str1} {str2}'
print(msg)
#print('hello world')


# %%
print('----'*10)
# if   ... for   
for x in range(1, 10+1, 1):
    if x%2 == 0:
        msg = f'even {x}'
    else:
        msg = f'odd {x}'
    print(msg)

# %%
#이중 for 문 : 전체 구구단 표
'''
2x1=2     9x1=9
...
2x9=18    9x9=81
'''