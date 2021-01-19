def is_valid(x,y):
    if x<0 or x>=N: return False
    if y<0 or y>=M: return False
    if field[x][y]!=1: return False
    return True

def bfs(x, y):
    queue = []
    field[x][y] = 2
    queue.append([x,y])

    while queue:
        cur_x,cur_y = queue.pop(0)

        for i in range(4):
            if is_valid(cur_x+dirs[i][0],cur_y+dirs[i][1]):
                field[cur_x+dirs[i][0]][cur_y+dirs[i][1]] = 2
                queue.append([cur_x+dirs[i][0],cur_y+dirs[i][1]])

T = int(input())
dirs = [(-1,0),(0,1),(1,0),(0,-1)]

for test_case in range(T):
    N,M,K = map(int,input().split())
    field = [[0] * M for _ in range(N)]
    num_worms = 0

    for _ in range(K):
        X,Y = map(int,input().split())
        field[X][Y] = 1

    for i in range(N):
        for j in range(M):
            if field[i][j] == 1:
                num_worms += 1
                bfs(i,j)

    print(num_worms)