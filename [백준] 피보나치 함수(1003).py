fibos = [[] for _ in range(41)]
fibos[0] = [1,0]
fibos[1] = [0,1]
fibos[2] = [1,1]

for i in range(3,41):
    fibos[i] = [ fibos[i-1][0]+fibos[i-2][0], fibos[i-1][1]+fibos[i-2][1] ]

T = int(input())
for i in range(T):
    N = int(input())
    print(fibos[N][0], fibos[N][1])