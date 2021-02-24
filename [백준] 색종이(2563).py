N = int(input())
board = [[0]*100 for _ in range(100)]
while N > 0:
    x, y = map(int,input().split())
    for i in range(x,x+10):
        for j in range(y,y+10):
            board[i][j] = 1
    N -= 1
answer = 0
for i in range(len(board)):
    for j in range(len(board[i])):
        if board[i][j] == 1:
            answer += 1
print(answer)