def compare_dungchi(d1, d2):
    if d1[0] < d2[0]:
        if d1[1] < d2[1]:
            return True
    return False

def get_rank(dungchis,idx):
    cnt=0
    for i in range(len(dungchis)):
        if i==idx: continue
        if compare_dungchi(dungchis[idx],dungchis[i]):
            cnt+=1
    return cnt

N=int(input())
dungchis=[]
ranks=[0 for _ in range(N)]
for i in range(N):
    dungchis.append(list(map(int,input().split())))
for i in range(N):
    ranks[i] = get_rank(dungchis,i)+1
for i in range(N):
    print(ranks[i],end=' ')
print()