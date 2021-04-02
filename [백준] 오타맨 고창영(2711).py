T = int(input())

for test_case in range(T):
    miss_idx, str = input().split()
    miss_idx = int(miss_idx)
    print(str[:miss_idx-1]+str[miss_idx:])