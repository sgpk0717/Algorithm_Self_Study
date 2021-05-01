def check_succession(str):
    max_succession = 0

    succession = 1
    pointer = str[0]
    for i in range(1,len(str)):
        if str[i] == pointer:
            succession += 1
        else:
            pointer = str[i]
            max_succession = max(max_succession,succession)
            succession = 1
    return max(max_succession,succession)


for i in range(3):
    print(check_succession(input()))