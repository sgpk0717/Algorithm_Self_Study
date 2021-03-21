A, B = map(int,input().split())

nums = []
num = 1
while len(nums) <= 1000:
    for i in range(num):
        nums.append(num)
    num += 1

s = 0
for i in range(A-1,B):
    s += nums[i]
print(s)