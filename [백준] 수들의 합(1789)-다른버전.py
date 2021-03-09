S = int(input())

def sum_one2n(n):
    return int(((1+n)*n)/2)

low = 1
high = S

max_n = 0
while low <= high:
    mid = (low + high) // 2
    if sum_one2n(mid) <= S:
        max_n = mid
        low = mid + 1
    else:
        high = mid - 1
print(max_n)
