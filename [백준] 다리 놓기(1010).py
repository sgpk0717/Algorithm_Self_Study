import sys
T = int(input())

for test_case in range(T):
    N, M = map(int,sys.stdin.readline().split())
    if N==M:
        print(1)
        continue
    mother = 1
    son = 1
    for i in range(1,N+1):
        mother *= i
    for i in range(M-N+1,M+1):
        son *= i
    print(int(son/mother))