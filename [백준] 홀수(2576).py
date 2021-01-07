sum_num=0
min_num=101
for i in range(7):
    num = int(input())
    if num%2==1:
        sum_num += num
        min_num = min(min_num,num)
if min_num == 101:
    print(-1)
else:
    print(sum_num)
    print(min_num)