import sys
from collections import Counter

N = int(input())
Ns = Counter(map(int,sys.stdin.readline().split()))

M = int(input())
Ms = list(map(int,sys.stdin.readline().split()))

for m in Ms:
    print(Ns[m],end=' ')
print()