import sys

N = int(input())
q = []
for i in range(N):
    ins = sys.stdin.readline().rstrip()
    if ins[:2] == 'pu':
        q.append(int(ins[5:]))
    elif ins[:2] == 'po':
        if len(q) != 0:
            print(q.pop(0))
        else:
            print(-1)
    elif ins[:2] == 'si':
        print(len(q))
    elif ins[:2] == 'em':
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif ins[:2] == 'fr':
        if len(q) != 0:
            print(q[0])
        else:
            print(-1)
    elif ins[:2] == 'ba':
        if len(q) != 0:
            print(q[-1])
        else:
            print(-1)
