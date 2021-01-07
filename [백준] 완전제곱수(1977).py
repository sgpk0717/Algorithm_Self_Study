import math
M = int(input())
N = int(input())
s=0
m=1000001
for i in range(M, N+1):
    if pow(int(math.sqrt(i)),2) == i:
        s+=i
        m = min(m,i)
if m == 1000001:
    print(-1)
else:
    print(s)
    print(m)