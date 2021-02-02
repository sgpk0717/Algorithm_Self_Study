S = input()
word_list = []
for i in range(len(S)):
    word_list.append(S[i:])
for i in sorted(word_list):
    print(i)