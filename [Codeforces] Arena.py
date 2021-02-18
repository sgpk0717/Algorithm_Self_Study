import sys
T = int(input())
for test_case in range(T):
    n = int(input())
    heroes = list(map(int,sys.stdin.readline().rstrip().split()))
    heroes.sort()
    index = -1
    for i in range(1,len(heroes)):
        if heroes[i] != heroes[i-1]:
            index = i
            break
    if index == -1:
        print(0)
    else:
        print(len(heroes) - index)