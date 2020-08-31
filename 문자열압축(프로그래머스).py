def count_same_string(str_len, index, s) :
    count=1
    target = s[index:index+str_len]
    index+=str_len
    while index+str_len<=len(s):
        if s[index:index+str_len]==target:
            count+=1
            index+=str_len
        else:
            break

    return count


def solution(s):
    answer = 0
    zip=[0 for i in range(int(len(s)/2)+1)]
    zip[0] = len(s)

    for i in range(1,len(zip)):
        length=0
        index=0
        str_zipped=""
        while index<len(s):
            target = s[index:index+i]
            retv = count_same_string(i,index,s)
            index += retv*i
            if retv>1:
                length+=i+1
                str_zipped+=str(retv)
            else:
                length+=i
            str_zipped+=target
        zip[i] = length+(len(s)-index)

    print(min(zip))

    return answer

ss = "abcdefabcdefdededededede"
solution(ss)