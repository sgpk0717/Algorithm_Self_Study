import sys

def is_possible(limit, jibang, M):
    for i in range(len(jibang)):
        if jibang[i] > limit:
            M -= limit
        else:
            M -= jibang[i]
        if M < 0:
            return False
    return True

N = int(input())
jibang =list(map(int,sys.stdin.readline().rstrip().split()))
M = int(input())

if sum(jibang) <= M:
    print(max(jibang))
else:
    low = 1
    high = M
    max_limit = 0
    while low <= high:
        mid = (low + high) // 2
        if is_possible(mid,jibang,M):
            max_limit = mid
            low = mid + 1
        else:
            high = mid - 1
    print(max_limit)