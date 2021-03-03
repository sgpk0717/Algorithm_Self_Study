while True:
    try:
        s = input()
        l,u,n,w = 0,0,0,0
        for c in s:
            if c.islower():
                l += 1
            elif c.isupper():
                u += 1
            elif c.isnumeric():
                n += 1
            elif c == ' ':
                w += 1
        print(l,u,n,w)
    except:
        break
