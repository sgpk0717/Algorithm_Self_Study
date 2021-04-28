A = list(map(int,input().split()))
B = list(map(int,input().split()))

win_A = 0
win_B = 0
for i in range(10):
    if A[i] > B[i]:
        win_A += 1
    elif A[i] < B[i]:
        win_B += 1

if win_A > win_B:
    print('A')
elif win_A < win_B:
    print('B')
else:
    print('D')
