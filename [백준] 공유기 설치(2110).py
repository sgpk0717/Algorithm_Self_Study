import bisect
import sys

def is_possible(interval, houses, remain):
    prev = houses[0]
    remain -= 1

    for i in range(1, len(houses)):
        if houses[i] - prev >= interval:
            remain -= 1
            prev = houses[i]
        if remain == 0:
            return True
    return False

N, C = map(int,input().split())

houses = []
for i in range(N):
    pos = int(sys.stdin.readline().rstrip())
    houses.append(pos)
houses.sort()
# print(houses)

low = 1
high = houses[-1] - houses[0]
answer = 0
while low <= high:
    mid = (low + high) // 2

    if is_possible(mid, houses, C):
        low = mid + 1
        answer = mid
    else:
        high = mid - 1
print(answer)