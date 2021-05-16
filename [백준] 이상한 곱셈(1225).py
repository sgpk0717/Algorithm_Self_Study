import sys
from collections import Counter

input = sys.stdin.readline

a, b = input().split()

result = 0

a_cntr = Counter(a)
b_cntr = Counter(b)

for a_k, a_v in a_cntr.items():
    for b_k, b_v in b_cntr.items():
        result += int(a_k)*int(b_k)*b_v*a_v

print(result)
