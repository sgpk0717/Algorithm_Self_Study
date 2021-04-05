A, B, V = map(int,input().split())

start = A
day_rise = A - B
cnt = 1
if start < V:
    if (V - start) % day_rise == 0:
        cnt += (V - start) // day_rise
    else:
        cnt += ((V - start) // day_rise) + 1
print(cnt)