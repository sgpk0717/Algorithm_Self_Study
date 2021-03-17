import sys
import copy
from collections import deque

input = sys.stdin.readline

def is_valid(x, y, check, I):
    if x < 0 or x >= I: return False
    if y < 0 or y >= I: return False
    if check[x][y]: return False
    return True

def bfs(sx, sy, dx, dy, I):
    check = [[False] * I for _ in range(I)]
    dirs = [(-2,-1),(-2,1),(-1,2),(1,2),(2,1),(2,-1),(1,-2),(-1,-2)]
    move = 1
    q = deque()
    q.append([sx,sy])
    check[sx][sy] = True

    while len(q) != 0:
        len_q = len(q)

        for i in range(len_q):
            tx, ty = q.popleft()
            for d in dirs:
                mx, my = tx+d[0], ty+d[1]
                if is_valid(mx,my,check,I):
                    if mx == dx and my == dy:
                        return move
                    check[mx][my] = True
                    q.append([mx,my])
        move += 1
    return 0

T = int(input())
for test_case in range(T):
    I = int(input())
    sx, sy = map(int,input().split())
    dx, dy = map(int,input().split())
    print(bfs(sx, sy, dx, dy, I))
