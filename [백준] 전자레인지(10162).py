T = int(input())
if T % 10 != 0:
    print(-1)
else:
    cnt_A, cnt_B, cnt_C = 0, 0, 0
    while T > 0:
        if T >= 300:
            cnt_A += 1
            T -= 300
        elif T >= 60:
            cnt_B += 1
            T -= 60
        else:
            cnt_C += 1
            T -= 10
    print(cnt_A,cnt_B,cnt_C)