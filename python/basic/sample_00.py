# %%
a = 1
print(a, type(a))

# %%
a = 1.123
print(a, type(a))

a = 'abcedf' # ""  도 가능
print(a, type(a))

# %%
# [] - data as List
a = [1,2,3,4,5,6,7,8,9,10]
print(a, type(a))

# %%
a = (1,2,3,4,5,6,7,8,9,10)
print(a, type(a))

# %%
a = {'1': 1, '2': 2,'3': 3} # dictionary(=map)
print(a, type(a))

a = 1
x = 0
b = 10

def fomular(a, x, b):
    return a*x+b

y = fomular(a, x,b)
print(y)

# %%
a=2/3
print(a)
print('%.2f'%a)








# %%
a = 1
b= 2
c = a+b
print(c)
print('Hellow world python~' * 3)

# %%
a = 1
(a, type(a))
a = 1.1
print(a, type(a))
print(a, type(a))
a = [1,2,3,4,5]
print(a, type(a))
a = (1,2,3,4,5)
print(a, type(a))
a = {'1': 1, '2': 2, '3' : 3}
print(a, type(a))

# %%
a = 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
(a, type(a))


# %%
a = 'ABCDEF'
print(a, type(a)) # ABCDEF <class 'str'>
print(a[5], type(a)) # F <class 'str'>
a = ['A', 'B', 'C', 'D', 'E', 'F']
print(a[5], type(a)) # F <class 'list'>
print(a, type(a)) # ['A', 'B', 'C', 'D', 'E', 'F'] <class 'list'>
# %%
# slice
print(a[:3], type(a)) # ['A', 'B', 'C'] <class 'list'>
print(a[1:3], type(a))#['B', 'C'] <class 'list'>
print(a[3:], type(a)) #['D', 'E', 'F'] <class 'list'>
'''
# C++ version slice
int start_index = 3;
int finish_index = a.length()
char* pArr = new char[finish_index-start_index];
memset((void*)pArr, 0xff, sizeof(char)*(finish_index-start_index))
int new_i = 0;
for(int i = start_index; i<finish_index; i++)
{
    pArr[new_i] = a[i];
    new_i++;
}
'''

# %%
# 문자열
a = 'abc'
b = 'ABC'
c = a+b
print(c) #abcABC
c = a*3
print(c) #abcabcabc
c = b*3
print(c) #ABCABC
#c = b**3 # Error
#print(c)

# %%
# 문자열 길이 구하기: len()

a = 'abcdefgabcdefgabcdefgabcdefg'
print(len(a)) # 28
a = ['A', 'B', 'C', 'D', 'E', 'F']
print(len(a)) # 6
a = ('A', 'B', 'C', 'D', 'E', 'F')
print(len(a)) # 6
a = 1 # 이터러블한 데이터를 넣어주면 len() 에러 발생
print(len(a)) # Error

# %%
# 문자열 포맷팅
# %s 
## 중요 - 가장 많이 사용하는 것들 중 하나(80% 정도 사용)
kor = 88
eng = 95
math = 97
sum = kor + eng + math
avg = sum /3
msg = 'sum = %d, avg = %.2f' % (sum, avg)
msg = f'sum = {sum}, avg = {avg}'
msg = f'sum = {sum}, avg = {avg:0.3f}'

print(msg) # sum = 280, avg = 93.33

# %%
# 입출력
name = input('input name : ')
print(f'{name}' + '님 안녕하세요')

# %%
first = input('input 1st Value : ')
second = input('input 2st Value : ')
print(first, type(first))
first = int(first)  # string -> int
second = int(second)# string -> int
print(f'a = {first}, b = {second}, + a+b = {first+second}')


# %%
age=int(input('나이를 입력해주세요:')) #input-> string -> int
fee = 2000
if age > 65: fee = 0
elif age <30:
    fee = 2000
elif age < 5:
    fee = 1
else:
    fee = 3000

print('나이:%d세' %age)
print('입장료:%d원' %fee)

# %%
ans1 = input("''사자''의 영어 단어는 무엇일까요?")
result = '땡! 틀렸습니다.'
if ans1 == 'lion':
    result = '딩동댕! 참 잘했어요'
    print(result)
    ans2 = input("'오렌지'의 영어단어는 무엇일까요?")
    result='땡!틀렸습니다.'
    if ans2 == 'orange':
        result = '딩동댕! 참 잘했어요'
        print(result)
    else: 
        result = '땡! 틀렸습니다.'
        print(result)
else: 
    print(result)


# %%
############# 책


# if문 기초
x = 11
if x > 10:
    print('x is ')
    print('     larger than 10.')
else:
    print('x is smaller than 11')
# %%
# 배열 기초
for i in [1,2,3]:
    print(i)

# %%
# 배열 + for문
num = [2, 4, 6, 8, 10]
for i, n in enumerate(num):
#for i in range(len(num)):
    num[i] = num[i] * 2
print(num)

# %%
