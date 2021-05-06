T = int(input())

for test_case in range(T):
    nums = list(map(int,input().split()))
    s = 0
    min_num = 101
    for num in nums:
        if num % 2 == 0:
            s += num
            min_num = min(num, min_num)
    print(s, min_num)