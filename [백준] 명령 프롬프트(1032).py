N = int(input())
file_names = []
for i in range(N):
    file_names.append(input())
answer=[]
for i in range(len(file_names[0])):
    answer.append(file_names[0][i])
    for j in range(N):
        if file_names[j][i] != answer[-1]:
            answer[-1] = '?'
            break
print(''.join(answer))
