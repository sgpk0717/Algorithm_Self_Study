N = int(input())
if N==0:
    print(0)
else:
    dp=[0]+[0]*N
    dp[1]=1
    for i in range(2,N+1):
        dp[i]=dp[i-1]+dp[i-2]
    print(dp[-1])