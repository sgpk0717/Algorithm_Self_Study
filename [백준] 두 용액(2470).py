import sys

N = int(input())
liquids = list(map(int,sys.stdin.readline().rstrip().split()))
liquids.sort()
min_sum = 2000000000
answer = [0,0]

for i in range(len(liquids)):
    src = liquids[i]

    low = i + 1
    high = len(liquids) - 1
    while low <= high:
        mid = (low + high) // 2
        s = src + liquids[mid]
        if s == 0:
            min_sum = s
            answer = [liquids[i], liquids[mid]]
            break
        elif s < 0:
            low = mid + 1
        else:
            high = mid - 1

        if abs(s) < min_sum:
            min_sum = abs(s)
            answer = [liquids[i], liquids[mid]]
    if min_sum == 0:
        break

answer.sort()
print(answer[0], answer[1])
