T=int(input())

for i in range(T):
    H, W, N = map(int,input().split())
    floor = N%H
    ho = N//H
    if floor==0:
        floor=str(H)
    else:
        floor=str(floor)
        ho+=1

    if ho < 10:
        ho = '0'+str(ho)
    else:
        ho = str(ho)
    print(floor+ho)