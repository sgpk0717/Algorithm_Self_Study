def check_valid(snail, x, y, N):
    if x<0 or x>=N: return False
    if y<0 or y>=N: return False
    if snail[x][y]!=0: return False
    return True

def fill_snail(x,y,cnt, N, snail, dir):
    if(cnt>N*N): return
    snail[x][y] = cnt
    if not check_valid(snail,x+dirs[dir][0],y+dirs[dir][1],N):
        dir = (dir+1)%4
    fill_snail(x+dirs[dir][0],y+dirs[dir][1],cnt+1,N,snail,dir)

T = int(input())
dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

for test_case in range(1,T+1):
    N = int(input())

    snail = [[0]*N for i in range(N)]
    fill_snail(0,0,1,N,snail,0)
    print('#%d'%test_case)
    for x in snail:
        for y in x:
            print(y,end=' ')
        print()
