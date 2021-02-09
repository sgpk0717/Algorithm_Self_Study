import sys
N = int(input())
names = [0 for _ in range(26)]
for i in range(N):
    name = sys.stdin.readline().rstrip()
    names[ ord(name[0])-ord('a') ] += 1

answers = []
for i in range(26):
    if names[i] >= 5:
        answers.append(chr(ord('a')+i))
if len(answers) == 0:
    print('PREDAJA')
else:
    for i in range(len(answers)):
        print(answers[i],end='')