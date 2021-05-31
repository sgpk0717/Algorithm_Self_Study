nums = list(map(int,input().split()))
nums.sort()
order = input()

for c in order:
    if c == 'A':
        print(nums[0], end=' ')
    elif c == 'B':
        print(nums[1], end=' ')
    else:
        print(nums[2], end=' ')
print()
