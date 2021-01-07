from collections import defaultdict
N, M = map(int,input().split())
board = []
rx,ry,bx,by = 0,0,0,0
for i in range(N):
    board.append(list(input()))
    for j in range(M):
        if board[i][j] == 'R':
            board[i][j] = '.'
            rx, ry = i, j
        elif board[i][j] == 'B':
            bx, by = i, j
            board[i][j] = '.'

def tilt_up(rx, ry, bx, by, board):
    xys = []
    if rx < bx:
        xys.append([rx,ry,'R'])
        xys.append([bx,by,'B'])
    else:
        xys.append([bx,by,'B'])
        xys.append([rx,ry,'R'])

    while True:
        if board[xys[0][0]-1][xys[0][1]] == '#': break
        xys[0][0] -= 1
        if board[xys[0][0]][xys[0][1]] == 'O':    #만약에 이동한곳이 구멍이면
            if xys[0][2] == 'B':
                return -1,-1,-1,-1      #바로 -1을 리턴
            else:
                xys[0][0] = 77
                xys[0][1] = 77
                break

    while True:
        if board[xys[1][0] - 1][xys[1][1]] == '#': break
        xys[1][0] -= 1
        if board[xys[1][0]][xys[1][1]] == 'O':  # 만약에 이동한곳이 구멍이면
            if xys[1][2] == 'B':
                return -1, -1, -1, -1  # 바로 -1을 리턴
            else:
                xys[1][0] = 77
                xys[1][1] = 77
                break

    if xys[0][0] == 77 or xys[1][0] == 77: return 77, 77, 77, 77
    if xys[0][0] == xys[1][0] and xys[0][1] == xys[1][1]:
        xys[1][0] += 1
    if xys[0][2] == 'R':
        return xys[0][0],xys[0][1],xys[1][0],xys[1][1]
    else:
        return xys[1][0],xys[1][1],xys[0][0],xys[0][1]
def tilt_right(rx, ry, bx, by, board):
    xys = []
    if ry > by:
        xys.append([rx, ry, 'R'])
        xys.append([bx, by, 'B'])
    else:
        xys.append([bx, by, 'B'])
        xys.append([rx, ry, 'R'])

    while True:
        if board[xys[0][0]][xys[0][1]+1] == '#': break
        xys[0][1] += 1
        if board[xys[0][0]][xys[0][1]] == 'O':  # 만약에 이동한곳이 구멍이면
            if xys[0][2] == 'B':
                return -1, -1, -1, -1  # 바로 -1을 리턴
            else:
                xys[0][0] = 77
                xys[0][1] = 77
                break

    while True:
        if board[xys[1][0]][xys[1][1]+1] == '#': break
        xys[1][1] += 1
        if board[xys[1][0]][xys[1][1]] == 'O':  # 만약에 이동한곳이 구멍이면
            if xys[1][2] == 'B':
                return -1, -1, -1, -1  # 바로 -1을 리턴
            else:
                xys[1][0] = 77
                xys[1][1] = 77
                break

    if xys[0][0] == 77 or xys[1][0] == 77: return 77, 77, 77, 77

    if xys[0][0] == xys[1][0] and xys[0][1] == xys[1][1]:
        xys[1][1] -= 1

    if xys[0][2] == 'R':
        return xys[0][0], xys[0][1], xys[1][0], xys[1][1]
    else:
        return xys[1][0], xys[1][1], xys[0][0], xys[0][1]
def tilt_down(rx, ry, bx, by, board):
    xys = []
    if rx > bx:
        xys.append([rx, ry, 'R'])
        xys.append([bx, by, 'B'])
    else:
        xys.append([bx, by, 'B'])
        xys.append([rx, ry, 'R'])
    # print(xys)
    while True:
        if board[xys[0][0] + 1][xys[0][1]] == '#': break
        xys[0][0] += 1
        if board[xys[0][0]][xys[0][1]] == 'O':  # 만약에 이동한곳이 구멍이면
            if xys[0][2] == 'B':
                return -1, -1, -1, -1  # 바로 -1을 리턴
            else:
                xys[0][0] = 77
                xys[0][1] = 77
                break

    while True:
        if board[xys[1][0] + 1][xys[1][1]] == '#': break
        xys[1][0] += 1
        if board[xys[1][0]][xys[1][1]] == 'O':  # 만약에 이동한곳이 구멍이면
            if xys[1][2] == 'B':
                return -1, -1, -1, -1  # 바로 -1을 리턴
            else:
                xys[1][0] = 77
                xys[1][1] = 77
                break

    if xys[0][0] == 77 or xys[1][0] == 77: return 77, 77, 77, 77

    if xys[0][0] == xys[1][0] and xys[0][1] == xys[1][1]:
        xys[1][0] -= 1

    if xys[0][2] == 'R':
        return xys[0][0], xys[0][1], xys[1][0], xys[1][1]
    else:
        return xys[1][0], xys[1][1], xys[0][0], xys[0][1]
def tilt_left(rx, ry, bx, by, board):
    xys = []
    if ry < by:
        xys.append([rx, ry, 'R'])
        xys.append([bx, by, 'B'])
    else:
        xys.append([bx, by, 'B'])
        xys.append([rx, ry, 'R'])

    while True:
        if board[xys[0][0]][xys[0][1] - 1] == '#': break
        xys[0][1] -= 1
        if board[xys[0][0]][xys[0][1]] == 'O':  # 만약에 이동한곳이 구멍이면
            if xys[0][2] == 'B':
                return -1, -1, -1, -1  # 바로 -1을 리턴
            else:
                xys[0][0] = 77
                xys[0][1] = 77
                break

    while True:
        if board[xys[1][0]][xys[1][1] - 1] == '#': break
        xys[1][1] -= 1
        if board[xys[1][0]][xys[1][1]] == 'O':  # 만약에 이동한곳이 구멍이면
            if xys[1][2] == 'B':
                return -1, -1, -1, -1  # 바로 -1을 리턴
            else:
                xys[1][0] = 77
                xys[1][1] = 77
                break

    if xys[0][0] == 77 or xys[1][0] == 77: return 77, 77, 77, 77

    if xys[0][0] == xys[1][0] and xys[0][1] == xys[1][1]:
        xys[1][1] += 1

    if xys[0][2] == 'R':
        return xys[0][0], xys[0][1], xys[1][0], xys[1][1]
    else:
        return xys[1][0], xys[1][1], xys[0][0], xys[0][1]

answer = 99999
check_board = defaultdict(bool)
queue = []
queue.append([[rx,ry,bx,by],0])
check_board[(rx, ry, bx, by)] = True

while len(queue)!=0:
    current,cnt = queue.pop(0)
    if cnt >= 10: continue

    cnt+=1
    rx, ry, bx, by = tilt_up(current[0], current[1], current[2], current[3], board)
    if rx == 77:
        if answer > cnt: answer = cnt
    elif rx != -1:
        if not check_board[(rx, ry, bx, by)]:
            check_board[(rx, ry, bx, by)] = True
            queue.append([[rx, ry, bx, by], cnt])

    rx, ry, bx, by = tilt_right(current[0], current[1], current[2], current[3], board)
    if rx == 77:
        if answer > cnt: answer = cnt
    elif rx != -1:
        if not check_board[(rx, ry, bx, by)]:
            check_board[(rx, ry, bx, by)] = True
            queue.append([[rx, ry, bx, by], cnt])

    rx, ry, bx, by = tilt_down(current[0], current[1], current[2], current[3], board)
    if rx == 77:
        if answer > cnt: answer = cnt
    elif rx != -1:
        if not check_board[(rx, ry, bx, by)]:
            check_board[(rx, ry, bx, by)] = True
            queue.append([[rx, ry, bx, by], cnt])

    rx, ry, bx, by = tilt_left(current[0], current[1], current[2], current[3], board)
    if rx == 77:
        if answer > cnt: answer = cnt
    elif rx != -1:
        if not check_board[(rx, ry, bx, by)]:
            check_board[(rx, ry, bx, by)] = True
            queue.append([[rx, ry, bx, by], cnt])

if answer == 99999:
    print(-1)
else:
    print(answer)