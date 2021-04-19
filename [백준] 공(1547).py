M = int(input())
ball = 1
for i in range(M):
    s, e = map(int,input().split())
    if s == ball:
        ball = e
    elif e == ball:
        ball = s
print(ball)
