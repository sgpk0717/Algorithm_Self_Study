import sys

def is_possible(target, levels, remain):
    for i in range(len(levels)):
        if levels[i] < target:
            remain -= target - levels[i]
        if remain < 0:
            return False
    return True

N, K = map(int,input().split())

levels = []
for i in range(N):
    levels.append(int(sys.stdin.readline().rstrip()))
levels.sort()
low = levels[0] + K//N
high = 1000000000

max_level = 0
while low <= high:
    mid = (low + high) // 2

    if is_possible(mid, levels, K):
        low = mid + 1
        max_level = mid
    else:
        high = mid - 1
print(max_level)
