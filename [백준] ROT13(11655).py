str1 = input()
for i in range(len(str1)):
    if str1[i].isupper():
        if ord(str1[i])-ord('A') >= 13:
            print(chr(ord(str1[i])-13),end='')
        else:
            print(chr(ord(str1[i])+13),end='')
    elif str1[i].islower():
        if ord(str1[i])-ord('a') >= 13:
            print(chr(ord(str1[i])-13),end='')
        else:
            print(chr(ord(str1[i])+13),end='')
    else:
        print(str1[i],end='')