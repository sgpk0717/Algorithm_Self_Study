K = int(input())
dp = [[0,0] for _ in range(46)]
dp[0] = [1,0]
for i in range(1,46):
    dp[i] = [dp[i-1][1], dp[i-1][0]+dp[i-1][1]]
print(dp[K][0],dp[K][1])