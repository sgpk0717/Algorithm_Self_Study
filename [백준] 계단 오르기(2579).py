N = int(input())
dp = [0 for _ in range(N)]
stair_scores = []
for i in range(N):
    stair_scores.append(int(input()))

if N>3:
    dp[0] = stair_scores[0]
    dp[1] = dp[0]+stair_scores[1]
    dp[2] = stair_scores[2]+max(stair_scores[0], stair_scores[1])

    for i in range(3,N):
        dp[i] = max(stair_scores[i]+stair_scores[i-1]+dp[i-3]
                    ,stair_scores[i]+dp[i-2])

    print(dp[-1])
elif N==3:
    print(stair_scores[2]+max(stair_scores[0], stair_scores[1]))

elif N==2:
    print(stair_scores[0]+stair_scores[1])
else:
    print(stair_scores[0])