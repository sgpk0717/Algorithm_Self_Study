import sys
from collections import defaultdict
input = sys.stdin.readline

T = int(input())

for test_case in range(T):
    N = int(input())
    memory = defaultdict(int)
    for num in input().split():
        memory[num] = 1

    M = int(input())
    for num in input().split():
        print(memory[num])