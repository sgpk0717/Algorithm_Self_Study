from collections import defaultdict
import sys
T = int(input())

for test_case in range(T):
    N = int(input())
    clothes = defaultdict(int)
    for _ in range(N):
        name, category = sys.stdin.readline().rstrip().split()
        clothes[category] += 1
    answer = 1
    for v in clothes.values():
        answer *= (v+1)
    print(answer - 1)