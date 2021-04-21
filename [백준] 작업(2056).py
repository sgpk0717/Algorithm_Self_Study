N = int(input())
dp = [0 for _ in range(N+1)]
for i in range(N):
    info = list(map(int,input().split()))
    max_pre_time = 0
    for pre_op in info[2:]:
        max_pre_time = max(max_pre_time, dp[pre_op])
    dp[i+1] = max_pre_time + info[0]
print(max(dp))