import sys
input = sys.stdin.readline

N, M = map(int,input().split())

memo = {}
for i in range(N):
    address, password = input().rstrip().split()
    memo[address] = password

for i in range(M):
    print(memo[input().rstrip()])