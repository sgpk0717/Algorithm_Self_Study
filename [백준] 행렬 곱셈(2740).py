N, M = map(int,input().split())

mat1 = []
for i in range(N):
    mat1.append(list(map(int,input().split())))

M, K = map(int,input().split())

mat2 = []
for i in range(M):
    mat2.append(list(map(int,input().split())))

result = [[0]*K for _ in range(N)]
for i in range(N):
    for j in range(M):
        for k in range(K):
            result[i][k] += mat1[i][j]*mat2[j][k]
for n in result:
    for m in n:
        print(m,end=' ')
    print()