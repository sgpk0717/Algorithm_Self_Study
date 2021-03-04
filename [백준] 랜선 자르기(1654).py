import sys

K, N = map(int,input().split())
seon = []
max_seon = 0
for i in range(K):
    seon.append(int(sys.stdin.readline().rstrip()))
    max_seon = max(max_seon, seon[i])

low = 1
high = max_seon
answer = 0

while low <= high:
    mid = (low + high) // 2

    sum = 0
    for i in range(K):
        sum += seon[i] // mid

    if sum >= N:
        low = mid + 1
        answer = mid
    else:
        high = mid - 1
print(answer)