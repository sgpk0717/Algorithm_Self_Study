vrf=0
nums=list(map(int,input().split()))
for i in nums:
    vrf += i*i
print(vrf%10)