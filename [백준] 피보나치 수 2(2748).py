N = int(input())
fibos = [0 for _ in range(N+1)]
fibos[1]=1
for i in range(2,len(fibos)):
    fibos[i] = fibos[i-1]+fibos[i-2]
print(fibos[-1])