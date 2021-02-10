N, K = map(int,input().split())
che = [False for _ in range(N+1)]
answer = 0
for i in range(2,len(che)):
    if not che[i]:
        for j in range(i,len(che),i):
            if che[j]: continue
            che[j] = True
            K -= 1
            if K == 0:
                answer = j
                break
    if answer != 0:
        break
print(answer)