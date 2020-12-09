T=int(input())
for i in range(1, T+1):
    N=int(input())
    if N<=3:
        print(1)
    elif N<=5:
        print(2)
    else:
        dp=[0,1,1,1,2,2]+[0]*(N-3)
        for j in range(5,len(dp)):
            dp[j] = dp[j-1]+dp[j-5]
        print(dp[N])