import sys
N, M = map(int,input().split())
dogam = {}
for i in range(1,N+1):
    name = sys.stdin.readline().rstrip()
    dogam[name] = i
    dogam[str(i)] = name
for i in range(M):
    quiz = sys.stdin.readline().rstrip()
    print(dogam[quiz])