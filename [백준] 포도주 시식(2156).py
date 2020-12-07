N = int(input())
dp = [0 for _ in range(N)]
wines = [0 for _ in range(N)]
for i in range(N):
    wines[i] = int(input())

if N > 3:
    dp[0] = wines[0]
    dp[1] = dp[0] + wines[1]
    dp[2] = max(wines[0]+wines[2],wines[0]+wines[1],wines[1]+wines[2])

    for i in range(3, N):
        dp[i] = max(wines[i] + wines[i - 1] + dp[i - 3]
                    , wines[i] + dp[i - 2], dp[i-1])

    print(dp[-1])
elif N == 3:
    print(max(wines[0]+wines[2],wines[0]+wines[1],wines[1]+wines[2]))
elif N <= 2:
    print(sum(wines))