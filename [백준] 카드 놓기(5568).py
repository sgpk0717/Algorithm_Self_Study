from collections import defaultdict
from itertools import permutations
import sys

input = sys.stdin.readline
n = int(input())
k = int(input())

numbers = []
for i in range(n):
    numbers.append(input().rstrip())

unique = defaultdict(int)
for j in list(permutations(numbers,k)):
    unique[int(''.join(j))] += 1
print(len(unique))
