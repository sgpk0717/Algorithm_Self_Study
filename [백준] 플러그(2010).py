import sys

N = int(input())

total = 0
for i in range(N-1):
    multi_tap = int(sys.stdin.readline())
    total += (multi_tap - 1)
total += int(input())
print(total)