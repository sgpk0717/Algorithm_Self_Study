N = int(input())
k = int(input())
low = 0
high = k
mid = 0
answer = 0

while low <= high:
    mid = (low + high) // 2
    min_row = (mid//N)
    max_row = min(mid,N)
    num = 0
    num += min_row * N
    lb = 10000000000
    ub = 0
    if min_row == 0 or mid % N != 0:
        min_row = (mid//N)+1
    for i in range(min_row,max_row+1):
        mok = mid // i
        if mok >= N: continue
        num += mok

        if lb > i*(mok+1):
            lb = i*(mok+1)
        if ub < i*mok:
            ub = i*mok
    if num < k:
        low = mid + 1
    elif num == k:
        if num == N*N:
            answer = N*N
            break
        answer = ub
        break
    else:
        high = mid - 1
        answer = ub
print(answer)