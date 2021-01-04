def check_boundary(x, y):
    if x<0 or x>=N: return False
    if y<0 or y>=N: return False
    return True

N = int(input())
K = int(input())
board = [[0]*N for _ in range(N)]
for i in range(K):
    x, y = map(int,input().split())
    board[x-1][y-1] = 1

L = int(input())
turns = []
for i in range(L):
    turns.append(input().split())
    turns[i][0] = int(turns[i][0])

snake = []
cur_d = 1
cur_x = 0
cur_y = 0
cur_t = 0

snake.append((cur_x,cur_y))
board[cur_x][cur_y] = 2
while True:
    cur_t += 1
    if cur_d == 0:
        cur_x -= 1
    elif cur_d == 1:
        cur_y += 1
    elif cur_d == 2:
        cur_x += 1
    else:
        cur_y -= 1
    if not check_boundary(cur_x,cur_y): break
    if board[cur_x][cur_y] == 2: break

    if board[cur_x][cur_y] == 0:
        tail = snake.pop(0)
        board[ tail[0] ][ tail[1] ] = 0
    snake.append((cur_x,cur_y))
    board[cur_x][cur_y] = 2

    if len(turns)!=0:
        if turns[0][0] == cur_t:
            if turns[0][1] == 'L':
                cur_d = (cur_d-1)%4
            else:
                cur_d = (cur_d+1)%4
            turns.pop(0)

print(cur_t)