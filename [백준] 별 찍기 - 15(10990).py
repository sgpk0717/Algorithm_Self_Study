N = int(input())
print(' '*(N-1),end='*\n')
for i in range(1,N):
    for j in range(N-i-1):
        print(' ',end='')
    print('*',end='')
    for j in range(1+2*(i-1)):
        print(' ',end='')
    print('*',end='')
    print()