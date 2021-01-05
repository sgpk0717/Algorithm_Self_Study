N = int(input())
tree = [[] for _ in range(N)]
for i in range(N-1):
    tree[i].append(' '*(N-1-i))
for i in range(N):
    for j in range(i*2+1):
        if j%2 == 0:
            tree[i].append('*')
        else:
            tree[i].append(' ')

for i in range(N):
    print(''.join(tree[i]))