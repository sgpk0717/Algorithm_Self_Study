import sys
input = sys.stdin.readline

N, M = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
srt = []

p1 = 0
p2 = 0

while p1 < N and p2 < M:
    if A[p1] < B[p2]:
        srt.append(A[p1])
        p1 += 1
    else:
        srt.append(B[p2])
        p2 += 1

if p1 != N:
    srt.extend(A[p1:])
else:
    srt.extend(B[p2:])
for n in srt:
    print(n,end=' ')
print()