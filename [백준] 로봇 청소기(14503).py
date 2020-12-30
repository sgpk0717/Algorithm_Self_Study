import pprint

def check_valid(x,y):
    if x<0 or x>=N: return False
    if y<0 or y>=M: return False
    return True

def get_cleaned_by_dfs(cur_x, cur_y, cur_d, room):
    room[cur_x][cur_y]=2
    # for _ in range(N):
    #     print(room[_])
    # print()
    for _ in range(4):
        cur_d = (cur_d-1)%4
        if cur_d == 0:
            if check_valid(cur_x - 1, cur_y):
                if room[cur_x - 1][cur_y] == 0:
                    get_cleaned_by_dfs(cur_x - 1, cur_y, cur_d, room)
                    return
        elif cur_d == 1:
            if check_valid(cur_x, cur_y + 1):
                if room[cur_x][cur_y + 1] == 0:
                    get_cleaned_by_dfs(cur_x, cur_y + 1, cur_d, room)
                    return
        elif cur_d == 2:
            if check_valid(cur_x + 1, cur_y):
                if room[cur_x + 1][cur_y] == 0:
                    get_cleaned_by_dfs(cur_x + 1, cur_y, cur_d, room)
                    return
        else:
            if check_valid(cur_x, cur_y - 1):
                if room[cur_x][cur_y - 1] == 0:
                    get_cleaned_by_dfs(cur_x, cur_y - 1, cur_d, room)
                    return

    if cur_d == 0:
        if check_valid(cur_x + 1, cur_y):
            if room[cur_x + 1][cur_y] == 2:
                get_cleaned_by_dfs(cur_x + 1, cur_y, cur_d, room)
                return
    elif cur_d == 1:
        if check_valid(cur_x, cur_y - 1):
            if room[cur_x][cur_y - 1] == 2:
                get_cleaned_by_dfs(cur_x, cur_y - 1, cur_d, room)
                return
    elif cur_d == 2:
        if check_valid(cur_x - 1, cur_y):
            if room[cur_x - 1][cur_y] == 2:
                get_cleaned_by_dfs(cur_x - 1, cur_y, cur_d, room)
                return
    else:
        if check_valid(cur_x, cur_y + 1):
            if room[cur_x][cur_y + 1] == 2:
                get_cleaned_by_dfs(cur_x, cur_y + 1, cur_d, room)
                return
    return

N, M = map(int,input().split())
r, c, d = map(int,input().split())

room = []
for i in range(N):
    room.append(list(map(int,input().split())))

# for _ in range(N):
#     print(room[_])
# print()
get_cleaned_by_dfs(r,c,d,room)

ans=0
for i in range(N):
    for j in range(M):
        if room[i][j]==2:
            ans+=1
print(ans)