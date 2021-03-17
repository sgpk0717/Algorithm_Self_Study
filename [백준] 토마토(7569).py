import sys
from pprint import pprint
from collections import deque

def is_valid(h,x,y,H,N,M,check,boxes):
    if h < 0 or h >= H: return False
    if x < 0 or x >= N: return False
    if y < 0 or y >= M: return False
    if boxes[h][x][y] != '0': return False
    if check[h][x][y]: return False
    return True

def bfs(ripe_tomatoes, boxes, H, N, M, unripe):
    check = [[[False] * M for _ in range(N)] for _ in range(H) ]
    q = deque()
    for i in range(len(ripe_tomatoes)):
        q.append(ripe_tomatoes[i])
    dirs = [(-1,0,0),(1,0,0),(0,1,0),(0,-1,0),(0,0,1),(0,0,-1)]
    day = 0

    while len(q) != 0:
        len_q = len(q)

        for i in range(len_q):
            th, tx, ty = q.popleft()
            for d in dirs:
                mh = th + d[0]
                mx = tx + d[1]
                my = ty + d[2]
                if is_valid(mh,mx,my,H,N,M,check,boxes):
                    check[mh][mx][my] = True
                    boxes[mh][mx][my] = '1'
                    q.append((mh,mx,my))
                    unripe -= 1
        day += 1
        if unripe == 0:
            return day

    if unripe == 0:
        return day
    else:
        return -1


input = sys.stdin.readline

M, N, H = map(int,input().rstrip().split())

boxes = [[] for _ in range(H)]

ripe_tomatoes = []
unripe = 0
for i in range(H):
    for j in range(N):
        boxes[i].append(input().rstrip().split())
        for k in range(len(boxes[i][j])):
            if boxes[i][j][k] == '1':
                ripe_tomatoes.append((i,j,k))
            elif boxes[i][j][k] == '0':
                unripe += 1

if unripe == 0:
    print(0)
else:
    print(bfs(ripe_tomatoes,boxes,H,N,M,unripe))