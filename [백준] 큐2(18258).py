import sys
from collections import deque

input = sys.stdin.readline

n = int(input())

my_q = deque()
for _ in range(n):
    cmd = list(input().rstrip().split())

    if cmd[0] == "pop":
        if len(my_q) == 0:
            print(-1)
        else:
            print(my_q.popleft())
    elif cmd[0] == "size":
        print(len(my_q))
    elif cmd[0] == "empty":
        if len(my_q) == 0:
            print(1)
        else:
            print(0)
    elif cmd[0] == "front":
        if len(my_q) == 0:
            print(-1)
        else:
            print(my_q[0])
    elif cmd[0] == "back":
        if len(my_q) == 0:
            print(-1)
        else:
            print(my_q[-1])
    else:
        my_q.append(cmd[1])