boundary = [1,10,100,1000,10000,100000,1000000,10000000,100000000]

N = input()

cnt = 0
tmp = 10
for i in range(len(N)-1):
    t = tmp - boundary[i]
    cnt += t * (i + 1)
    tmp *= 10
cnt += (int(N)-boundary[len(N)-1]+1)*len(N)
print(cnt)
