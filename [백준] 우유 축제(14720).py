n = int(input())

cnt = 0
turn = 0
for milk in list(map(int, input().split())):
    if milk == turn:
        cnt += 1
        turn = (turn + 1) % 3

print(cnt)