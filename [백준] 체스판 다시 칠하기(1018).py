import sys
input = sys.stdin.readline

white_board = [ ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
                ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
                ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
                ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
                ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
                ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
                ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
                ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'] ]

black_board = [ ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
                ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
                ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
                ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
                ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
                ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
                ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
                ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'] ]

def painting_white(board,x,y,limit):
    cnt = 0
    for i in range(8):
        for j in range(8):
            if board[x + i][y + j] != white_board[i][j]:
                cnt += 1
            if cnt > limit:
                return cnt
    return cnt

def painting_black(board,x,y,limit):
    cnt = 0
    for i in range(8):
        for j in range(8):
            if board[x + i][y + j] != black_board[i][j]:
                cnt += 1
            if cnt > limit:
                return cnt
    return cnt

N, M = map(int,input().split())
board = []
for i in range(N):
    board.append([c for c in input().rstrip()])


min_painting = 300000
for i in range(N-8+1):
    for j in range(M-8+1):
        tmp = min(painting_black(board,i,j,min_painting),painting_white(board,i,j,min_painting))
        if tmp < min_painting:
            min_painting = tmp
print(min_painting)