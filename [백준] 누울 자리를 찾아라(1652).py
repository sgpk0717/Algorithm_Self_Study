import sys
input = sys.stdin.readline

N = int(input())
room_h = [input().rstrip() for _ in range(N)]
room_v = ['' for _ in range(N)]
for i in range(N):
    for j in range(N):
        room_v[i] += room_h[j][i]

for i in range(N):
    room_h[i] = room_h[i].split('X')
    room_v[i] = room_v[i].split('X')

hor = 0
ver = 0

for i in range(N):
    for j in range(len(room_h[i])):
        if room_h[i][j] != '' and room_h[i][j] != '.':
            hor += 1
    for j in range(len(room_v[i])):
        if room_v[i][j] != '' and room_v[i][j] != '.':
            ver += 1
print(hor,ver)