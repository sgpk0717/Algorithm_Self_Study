import sys
input = sys.stdin.readline
N, M = map(int,input().rstrip().split())

def is_possible(len_limit, lessons, M):
    s = 0
    M -= 1
    # print('Is possible?')
    # print('len_limit: %d'%len_limit)
    # print('M remained: %d'%M)
    # ss = []
    for i in range(len(lessons)):
        if s + lessons[i] <= len_limit:
            s += lessons[i]
            # print('s = %d + %d'%(s-lessons[i],lessons[i]))
        else:
            # ss.append(s)
            s = lessons[i]
            M -= 1
            # print('M remained: %d' % M)
            if M < 0:
                # print(ss)
                return -1
    # print(ss)
    if M > 0:
        return 1
    elif M == 0:
        return 0

lessons = list(map(int,input().rstrip().split()))

low = max(lessons)
high = sum(lessons)
answer = low

while low <= high:
    mid = (low + high) // 2
    # print('======================')
    # print('low: %d, high: %d, mid: %d'%(low,high,mid))
    result = is_possible(mid,lessons,M)
    if result == 1:
        high = mid - 1
        answer = mid
    elif result == 0:
        high = mid - 1
        answer = mid
    else:
        low = mid + 1
    # print('answer: %d'%answer)
print(answer)
