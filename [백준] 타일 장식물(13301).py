dp = [0 for _ in range(81)]

dp[0] = 0
dp[1] = 4
dp[2] = 6

for i in range(3,81):
    dp[i] = dp[i-2] + dp[i-1]

N = int(input())
print(dp[N])