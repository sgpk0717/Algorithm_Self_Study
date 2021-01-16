def is_valid(x, y):
    if x<0 or x>=N: return False
    if y<0 or y>=M: return False
    if visited[x][y]: return False
    if box[x][y]!=0: return False
    return True

M,N = map(int,input().split())
visited = [[False]*M for _ in range(N)]
already_riped = []
not_riped = 0
box = []

for i in range(N):
    box.append(list(map(int,input().split())))
    for j in range(len(box[i])):
        if box[i][j] == 1: already_riped.append([i,j])
        elif box[i][j] == 0: not_riped += 1

queue = []
for i in range(len(already_riped)):
    visited[already_riped[i][0]][already_riped[i][1]] = True
    queue.append([already_riped[i],1])

queue_idx = 0
queue_len = len(queue)
while queue_idx < queue_len:
    cur_xy, day = queue[queue_idx]
    x, y = cur_xy

    if is_valid(x+1, y):
        box[x+1][y] = day + 1
        queue.append([[x+1,y],day+1])
        visited[x+1][y] = True
        not_riped -= 1
    if is_valid(x, y+1):
        box[x][y+1] = day + 1
        queue.append([[x,y+1],day+1])
        visited[x][y+1] = True
        not_riped -= 1
    if is_valid(x-1, y):
        box[x-1][y] = day + 1
        queue.append([[x-1,y],day+1])
        visited[x-1][y] = True
        not_riped -= 1
    if is_valid(x, y-1):
        box[x][y-1] = day + 1
        queue.append([[x,y-1],day+1])
        visited[x][y-1] = True
        not_riped -= 1
    queue_len = len(queue)
    queue_idx += 1

max_day = 0
for i in range(N):
    for j in range(M):
        max_day = max(max_day, box[i][j])

if not_riped!=0:
    print(-1)
else:
    print(max_day-1)