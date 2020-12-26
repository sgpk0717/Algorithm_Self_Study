def count_0(yoots):
    cnt=0
    for i in range(4):
        if yoots[i]=='0':
            cnt+=1
    return cnt
def get_rank(zero_num):
    if zero_num==0:
        return 'E'
    elif zero_num==1:
        return 'A'
    elif zero_num==2:
        return 'B'
    elif zero_num==3:
        return 'C'
    else:
        return 'D'
for i in range(3):
    print(get_rank(count_0(input().split())))
