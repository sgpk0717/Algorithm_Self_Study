while True:
    p = input()
    if p == '0': break

    i=0
    j=len(p)-1
    while i<j:
        if p[i] != p[j]: break
        i+=1
        j-=1
    if i>=j:
        print('yes')
    else:
        print('no')