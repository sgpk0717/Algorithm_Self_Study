import sys
import bisect

N, M = map(int,input().split())
heights = list(map(int,sys.stdin.readline().rstrip().split()))
heights.sort()

min_height = 0
max_height = heights[-1]
min_idx= 0
max_cut_line = 0

partial_sum = 0

prev_target_idx = 0
prev_cut_line = 0
cut_line = -1

while True:
    mid_height = (min_height + max_height) // 2
    cut_line = mid_height
    if cut_line == prev_cut_line: break

    target_idx = bisect.bisect(heights,cut_line)
    if partial_sum == 0:
        for i in range(target_idx,N):
            partial_sum += heights[i] - cut_line
    else:
        if prev_cut_line < cut_line:    # 커트라인이 오른쪽으로
            partial_sum -= sum(heights[prev_target_idx:target_idx]) - (target_idx - prev_target_idx) * prev_cut_line
            partial_sum -= (N - target_idx) * (cut_line - prev_cut_line)
        else:                           # 커트라인이 왼쪽으로
            partial_sum += sum(heights[target_idx:prev_target_idx]) - (prev_target_idx-target_idx)*cut_line
            partial_sum += (N - prev_target_idx) * (prev_cut_line - cut_line)
    if partial_sum > M:
        max_cut_line = cut_line
        min_height = mid_height
    elif partial_sum == M:
        max_cut_line = cut_line
        break
    else:
        max_height = mid_height
    prev_cut_line = cut_line
    prev_target_idx = target_idx
print(max_cut_line)