import sys
input = sys.stdin.readline

N = int(input())
nums = list(map(int,input().split()))
cntr = sorted(set(nums))
dt = {}
for i in range(len(cntr)):
    dt[cntr[i]] = i
for i in range(N):
    print(dt[nums[i]],end=' ')