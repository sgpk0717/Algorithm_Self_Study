N=int(input())
left=N-1
right=1
for i in range(N-1):
    for j in range(left):
        print(' ',end='')
    for j in range(right):
        print('*', end='')
    print()
    left-=1
    right+=1
for i in range(N):
    for j in range(left):
        print(' ',end='')
    for j in range(right):
        print('*', end='')
    print()
    left+=1
    right-=1