import sys
sys.setrecursionlimit(1000000)

def check_valid(board, x, y, T):
    if x < 0 or x >= N: return False
    if y < 0 or y >= N: return False
    if board[x][y] != T: return False
    return True

def dfs(board, x, y, T, S):
    board[x][y] = S
    for i in range(4):
        if check_valid(board,x+dirs[i][0],y+dirs[i][1],T):
            dfs(board,x+dirs[i][0],y+dirs[i][1],T,S)

def get_zone_num(board):
    zone_num = 0
    for i in range(N):
        for j in range(N):
            if board[i][j] == 'R' or board[i][j] == 'G' or board[i][j] == 'B':
                dfs(board,i,j,board[i][j],zone_num)
                zone_num += 1
    return zone_num

N = int(input())
dirs = [(0,1),(1,0),(0,-1),(-1,0)]
board_NM = []
board_RG = []

for i in range(N):
    lines = sys.stdin.readline().rstrip()
    board_NM.append([_ for _ in lines])
    board_RG.append([_ for _ in lines.replace('G','R')])

print(get_zone_num(board_NM),get_zone_num(board_RG))