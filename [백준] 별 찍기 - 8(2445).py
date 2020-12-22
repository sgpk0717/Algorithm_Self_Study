N=int(input())
left=1
center=N*2-2
right=1

for i in range(N-1):
    for j in range(left):
        print('*',end='')
    for j in range(center):
        print(' ',end='')
    for j in range(right):
        print('*',end='')
    print()
    left+=1
    center-=2
    right+=1
for i in range(N):
    for j in range(left):
        print('*', end='')
    for j in range(center):
        print(' ', end='')
    for j in range(right):
        print('*', end='')
    print()
    left -= 1
    center += 2
    right -= 1