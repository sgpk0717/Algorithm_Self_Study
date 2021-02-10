max_sum = 0
max_idx = 0
for i in range(1,6):
    scores_sum = sum(map(int,input().split()))
    if scores_sum > max_sum:
        max_sum = scores_sum
        max_idx = i
    if i == 5:
        print(max_idx,max_sum)