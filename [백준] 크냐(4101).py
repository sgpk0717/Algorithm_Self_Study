while True:
    F, S = map(int,input().split())
    if F == 0 and S == 0: break
    if F > S:
        print('Yes')
    else:
        print('No')