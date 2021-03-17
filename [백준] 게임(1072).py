def cal_ratio(extra, win, total):
    return int((100.0 * (win+extra)) / (total+extra))


X, Y = map(int,input().split())
cur_z = int((100.0*Y)/X)

low = 1
high = 1000000000
min_extra = -1
changed_z = -1

while low <= high:
    mid = (low + high) // 2
    tmp = cal_ratio(mid,Y,X)

    if tmp == cur_z:
        low = mid + 1
    else:
        high = mid - 1
        min_extra = mid
        changed_z = tmp
if cur_z == changed_z:
    print(-1)
else:
    print(min_extra)