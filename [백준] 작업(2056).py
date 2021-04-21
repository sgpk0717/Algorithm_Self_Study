import sys
input = sys.stdin.readline

N = int(input())
dp = [0 for _ in range(N+1)]
for i in range(N):
    info = list(map(int,input().split()))
    max_pre_time = max(dp[pre_op] for pre_op in info[1:])
    dp[i+1] = max_pre_time + info[0]
print(max(dp))