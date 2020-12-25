T=int(input())

def get_max_priority(priorities,check_printed):
    pr_max=-1
    pr_idx=-1
    for i in range(len(priorities)):
        if check_printed[i]==True: continue
        if priorities[i][0] > pr_max:
            pr_max = priorities[i][0]
            pr_idx = i
    return pr_idx

for i in range(T):
    # print('===============================')
    N, M = map(int,input().split())
    check_printed = [False for _ in range(N)]
    priorities = []
    inputs = list(map(int,input().split()))
    for i in range(len(inputs)):
        priorities.append([inputs[i],i])
    cnt=0
    while cnt<N:
        # print('priorities:',priorities)
        # print('check_printed:',check_printed)
        pr_max = get_max_priority(priorities,check_printed)
        # print('pr_max:',pr_max)
        if M == priorities[pr_max][1]:
            print(cnt+1)
            break
        check_printed[pr_max] = True

        priorities = priorities[pr_max+1:] + priorities[:pr_max+1]
        check_printed = check_printed[pr_max+1:] + check_printed[:pr_max+1]

        cnt+=1

