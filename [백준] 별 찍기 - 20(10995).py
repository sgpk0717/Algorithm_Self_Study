def print_row(n):
    for i in range(n*2-1):
        if i % 2 == 0: print('*',end='')
        else: print(' ',end='')

N = int(input())

for i in range(N):
    if i % 2 == 1: print(' ',end='')
    print_row(N)
    print()