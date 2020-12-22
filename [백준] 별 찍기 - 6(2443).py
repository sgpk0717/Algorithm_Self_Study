N=int(input())
max_star = 1+(N-1)*2
left=0
for i in range(N):

    for j in range(left):
        print(' ',end='')
    for j in range(max_star):
        print('*',end='')
    print()
    left+=1
    max_star-=2