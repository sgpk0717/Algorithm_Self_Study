N = int(input())

if N<3:
    print(1)
else:
    dp = [[] for _ in range(N)]
    dp[0] = [0,1]
    for i in range(1,N):
        dp[i] = [ dp[i-1][0]+dp[i-1][1],dp[i-1][0] ]
    print(sum(dp[-1]))