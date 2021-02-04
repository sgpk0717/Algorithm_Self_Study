words = [['-']*15 for _ in range(5)]

for i in range(5):
    tmp = input()
    for j in range(len(tmp)):
        words[i][j] = tmp[j]

for j in range(15):
    for i in range(5):
        if words[i][j]!='-':
            print(words[i][j],end='')