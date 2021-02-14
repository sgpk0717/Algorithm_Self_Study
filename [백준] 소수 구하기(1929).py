def get_che(n):
    che = [True for _ in range(n + 1)]
    che[0], che[1] = False, False
    for i in range(2, len(che)):
        if che[i]:
            for j in range(i + i, len(che), i):
                che[j] = False
    return che

M, N = map(int,input().split())
era_che = get_che(N)
for i in range(M,N+1):
    if era_che[i]:
        print(i)