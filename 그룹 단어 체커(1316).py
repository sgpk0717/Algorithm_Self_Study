from collections import defaultdict

def check_complete(target_string):
    ddict = defaultdict(int)
    idx = 0
    while idx < len(target_string):
        target_char = target_string[idx]
        if ddict[target_char]>=1: return False
        ddict[target_char]+=1
        while idx+1 < len(target_string) and target_string[idx+1]==target_char:
            idx+=1
        idx+=1
    return True

N = int(input())
cnt = 0
# print('N:',N)
while N>0:
    target_string = input()
    # print('target_string:',target_string)
    if check_complete(target_string):
        cnt+=1
    N-=1

print(cnt)

