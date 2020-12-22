N=int(input())
max_star = 1
left=N-1
for i in range(N-1):
    for j in range(left):
        print(' ',end='')
    for j in range(max_star):
        print('*', end='')
    print()
    left -= 1
    max_star += 2

for i in range(N):
    for j in range(left):
        print(' ',end='')
    for j in range(max_star):
        print('*',end='')
    print()
    left+=1
    max_star-=2