N = int(input())

for i in range(N-1):
    print(' ',end='')
print('*')

left_white = N-2
center_white = 1
for i in range(N-2):
    for j in range(left_white):
        print(' ',end='')
    print('*', end='')
    for j in range(center_white):
        print(' ',end='')
    print('*')
    left_white-=1
    center_white+=2
for i in range(2*N-1):
    print('*', end='')
print()