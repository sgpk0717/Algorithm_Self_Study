A = input()
B = input()
len_A = len(A)
len_B = len(B)

field = [[(0,0,0)]*(len_A+1) for _ in range(len_B+1)]
for i in range(1,len(field)):
    for j in range(1, len(field[i])):
        if A[j-1] == B[i-1]:
            field[i][j] = (field[i-1][j-1][0]+1,i,j)
        else:
            if field[i-1][j][0] >= field[i][j-1][0]:
                field[i][j] = field[i-1][j]
            else:
                field[i][j] = field[i][j-1]

LCS = []
if field[-1][-1] != 0:
    print(field[-1][-1][0])
    x = len_B
    y = len_A
    while True:
        if field[x][y][0] == 0: break
        target_x = field[x][y][1]
        target_y = field[x][y][2]
        LCS.append(A[target_y-1])
        x = target_x - 1
        y = target_y - 1
    print(''.join(reversed(LCS)))