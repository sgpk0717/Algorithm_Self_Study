import sys
from collections import defaultdict
from pprint import pprint


def check_consistency(phone_numbers, num_dict):
    for i in range(len(phone_numbers)):
        if num_dict[phone_numbers[i]] > 0:
            return False
    return True

t = int(input())
for test_case in range(t):
    n = int(input())

    numbers = []
    num_dict = defaultdict(int)
    for i in range(n):
        num = sys.stdin.readline().rstrip()
        numbers.append(num)
        for j in range(1,len(num)):
            num_dict[num[:j]] += 1

    if check_consistency(numbers,num_dict):
        print('YES')
    else:
        print('NO')