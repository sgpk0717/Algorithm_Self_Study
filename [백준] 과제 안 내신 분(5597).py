set1 = {int(input()) for _ in range(28)}
set2 = {i for i in range(1,31)}
nums = list(set2-set1)
nums.sort()
print(nums[0])
print(nums[1])