def check_right_string(p):
    cnt=0
    for i in range(len(p)):
        if p[i]=='(':
            cnt+=1
        else:
            cnt-=1
        if cnt<0:
            return False
    return True

def split_string(p):
    cnt=0
    idx=0
    for i in range(len(p)):
        if p[i]=='(':
            cnt+=1
        else:
            cnt-=1
        if cnt==0:
            idx=i
            break
    return idx


def recursive(p):
    if p=='':
        return p
    print('=======In Recursive=======')
    print('p:',p)
    bi = split_string(p)
    print('bi:',bi)
    u = p[:bi+1]
    v = p[bi+1:]
    print('u:',u)
    print('v:',v)

    if not check_right_string(u):
        print('u is not right')
        temp = '('
        returned_v=recursive(v)
        temp+=returned_v
        print('returned_v:',returned_v)
        temp+=')'
        if not len(u)<=2:
            u = u[1:-1][::-1]
        else:
            u=''
        temp+=u
        print('temp:',temp)
        return temp

    else:
        print('u is right')
        returned_v = recursive(v)
        print('returned_v:',returned_v)
        u+=recursive(v)
        print('temp:',u)
        return u

recursive('(()())()')

