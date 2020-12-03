from collections import defaultdict

def solution(participant, completion):
    answer = ''

    dict = defaultdict(int)
    for c in completion:
        dict[c]+=1

    for p in participant:
        if dict.get(p,-1)==-1:
            answer = p
            break
        else:
            if dict[p]==0:
                answer = p
            else:
                dict[p]-=1



    return answer
