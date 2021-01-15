def is_valid(x, y):
    if x<0 or x>=N: return False
    if y<0 or y>=N: return False
    if house_map[x][y] != '1': return False
    return True

def bfs(x, y):
    house_map[x][y] = '2'
    sizes[-1] += 1

    if is_valid(x+1,y):
        bfs(x+1,y)
    if is_valid(x,y+1):
        bfs(x,y+1)
    if is_valid(x-1,y):
        bfs(x-1,y)
    if is_valid(x,y-1):
        bfs(x,y-1)

N=int(input())
house_map = []
sizes = []
for i in range(N):
    house_map.append(list(input()))

for i in range(N):
    for j in range(N):
        if house_map[i][j] == '1':
            sizes.append(0)
            bfs(i,j)

sizes.sort()
print(len(sizes))
for i in sizes:
    print(i)