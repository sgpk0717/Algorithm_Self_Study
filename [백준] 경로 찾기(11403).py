import sys

N = int(input())

matrix = []
for i in range(N):
    matrix.append(list(map(int,sys.stdin.readline().rstrip().split())))

edges = [[] for _ in range(N)]
for i in range(N):
    for j in range(N):
        if matrix[i][j] == 1:
            edges[i].append(j)
# print(edges)
answer = [[0]*N for _ in range(N)]
nodes = {i for i in range(N)}

while len(nodes) != 0:

    check = [False for i in range(N)]
    target = nodes.pop()

    # print('========================')
    # print('target: %d'%(target))

    q = []
    q.append(target)

    while len(q) != 0:
        tmp = q[0]
        # print('-----while-----')
        # print('tmp: %d'%tmp)
        for n in edges[tmp]:
            if not check[n]:
                # print('%d이 check되지 않았음.'%n)
                # print('%d,%d의 tmp가 1이 됨.' % (tmp, n))
                check[n] = True
                q.append(n)
                answer[target][n] = 1
        q.pop(0)
        # print(q)
for a in answer:
    for b in a:
        print(b,end=' ')
    print()
