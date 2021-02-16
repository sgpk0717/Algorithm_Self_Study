import sys

T = int(input())
for test_case in range(T):
    words = sys.stdin.readline().rstrip().split()
    for w in words:
        print(w[::-1],end=' ')
    print()