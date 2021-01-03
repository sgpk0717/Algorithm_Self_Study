chess_board = []
whites = []
answer=0
for i in range(8):
    chess_board.append(input())
    for j in range(8):
        if (i+j)%2==0:
            if chess_board[i][j] == 'F':
                answer+=1
print(answer)