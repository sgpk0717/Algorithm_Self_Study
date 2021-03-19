import sys
input = sys.stdin.readline

N, M = map(int,input().rstrip().split())
square = []
for i in range(N):
    square.append([int(i) for i in input().rstrip()])

max_area = 0
for i in range(N):
    for j in range(M):
        for k in range(j,M):
            if square[i][j] == square[i][k]:
                line_len = k - j
                if i + line_len < N:
                    if square[i+line_len][j] == square[i][j]:
                        if square[i+line_len][k] == square[i][j]:
                            max_area = max(max_area, (line_len+1)**2)
print(max_area)