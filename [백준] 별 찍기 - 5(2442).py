N=int(input())
left=N-1
center=1
for i in range(N):
    for j in range(left):
        print(' ',end='')
    for j in range(center):
        print('*',end='')
    print()
    left-=1
    center+=2