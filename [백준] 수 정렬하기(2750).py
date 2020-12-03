N = int(input())
lst = []
while N>0:
    num = int(input())
    lst.append(num)
    N-=1
lst.sort()
for i in lst:
    print(i)