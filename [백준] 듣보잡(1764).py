import sys
from collections import defaultdict
N, M = map(int,input().split())
dct = defaultdict(int)
dbj = []
for i in range(N):
    ipt = sys.stdin.readline().rstrip('\n')
    dct[ipt] += 1
for i in range(M):
    ipt = sys.stdin.readline().rstrip('\n')
    dct[ipt] += 1
    if dct[ipt] == 2:
        dbj.append(ipt)
dbj.sort()
print(len(dbj))
for i in range(len(dbj)):
    print(dbj[i])