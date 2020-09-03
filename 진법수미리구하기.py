def get_num(ten_num, n):
    nj=''

    while ten_num>0:
        mod = ten_num%n
        if mod >= 10:
            nj+=chr(55+mod)
        else:
            nj+=str(mod)
        ten_num//=n

    return nj[::-1]

def solution(n, t, m, p):
    answer=''
    total = t*m
    if total>=100 and total<1000:
        total//=2
    elif total>=1000 and total<10000:
        total//=3
    elif total>=10000 and total<100000:
        total//=4

    num_str = '0'
    for i in range(1,total):
        num_str+=get_num(i,n)

    idx=0
    while len(answer)!=t:
        if idx%m==p-1:
            answer+=num_str[idx]
        idx+=1

    return answer

print(solution(16,16,2,2))

