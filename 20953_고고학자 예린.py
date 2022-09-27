import sys

T = int(input())

for t in range(T):
    a, b = map(int, sys.stdin.readline().split())
    ab = a + b

    part_sum = 0
    if ab % 2 == 0: # 짝수이면
        part_sum = ((ab//2)-1) * ab + (ab//2)
    else:
        part_sum = (ab//2) * ab

    print(part_sum * ab)
