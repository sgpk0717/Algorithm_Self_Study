import sys
sys.setrecursionlimit(10**6)
dirs = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def is_valid(x,y,h,w,visited,maps):
    if x<0 or x>=h: return False
    if y<0 or y>=w: return False
    if visited[x][y]: return False
    if maps[x][y]!=1: return False
    return True

def dfs(x,y,h,w,visited,maps):
    maps[x][y] = 2

    for i in range(8):
        dx,dy = dirs[i]
        if is_valid(x+dx,y+dy,h,w,visited,maps):
            visited[x+dx][y+dy]=True
            dfs(x+dx,y+dy,h,w,visited,maps)

num_island = 0
while True:
    num_island = 0
    w, h = map(int,sys.stdin.readline().split())
    if w == 0: break

    maps = []
    visited = [[False]*w for _ in range(h)]
    for i in range(h):
        maps.append(list(map(int,sys.stdin.readline().split())))

    for i in range(h):
        for j in range(w):
            if maps[i][j] == 1:
                visited[i][j] = True
                dfs(i,j,h,w,visited,maps)
                num_island += 1

    print(num_island)