n = int(input())

words = [[] for i in range(0,51)]
for i in range(n):
    tmp = input()
    words[len(tmp)].append(tmp)

for i in range(len(words)):
    if len(words[i]) > 0:
        # print(words[i])
        word_set = set(words[i])
        words[i] = list(word_set)
        words[i].sort()
        # print(words[i])
        for j in range(len(words[i])):
            print(words[i][j])