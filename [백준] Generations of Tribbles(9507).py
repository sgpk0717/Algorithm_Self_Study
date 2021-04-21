T = int(input())
dp = [1 for _ in range(68)]
dp[2] = 2
dp[3] = 4
for i in range(4, 68):
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4]

for test_case in range(T):
    n = int(input())
    print(dp[n])