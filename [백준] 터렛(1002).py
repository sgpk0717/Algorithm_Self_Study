import sys
import math
T = int(input())
for test_case in range(T):
    x1,y1,r1,x2,y2,r2 = map(int,sys.stdin.readline().rstrip('\n').split())

    distance1 = math.sqrt(abs(x2-x1)**2 + abs(y2-y1)**2)
    if r1 < r2:
        if distance1 + r1 < r2:
            print(0)
        elif distance1 + r1 == r2:
            print(1)
        elif distance1 + r1 > r2:
            if distance1 < r1 + r2:
                print(2)
            elif distance1 == r1 + r2:
                print(1)
            elif distance1 > r1 + r2:
                print(0)
    elif r1 > r2:
        if distance1 + r2 < r1:
            print(0)
        elif distance1 + r2 == r1:
            print(1)
        elif distance1 + r2 > r1:
            if distance1 < r1 + r2:
                print(2)
            elif distance1 == r1 + r2:
                print(1)
            elif distance1 > r1 + r2:
                print(0)
    elif r1 == r2:
        if distance1 == 0:
            print(-1)
        elif 0 < distance1 < r1*2:
            print(2)
        elif distance1 > r1*2:
            print(0)
        else:
            print(1)