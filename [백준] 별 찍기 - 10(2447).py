N = int(input())

def print_board(board):
    for b in board:
        for c in b:
            if c == '-': print(' ',end='')
            else: print(c,end='')
        print()

def draw(x,y,n,board):
    if n == 3:
        for i in range(x,x+3):
            for j in range(y,y+3):
                if i == x+1 and j == y+1: continue
                board[i][j] = '*'
        return

    interval = n // 3

    for i in range(x,x+n,interval):
        for j in range(y,y+n,interval):
            if i == x+interval and j == y+interval: continue
            draw(i,j,interval,board)


board = [['-']*N for _ in range(N)]
draw(0,0,N,board)
print_board(board)
