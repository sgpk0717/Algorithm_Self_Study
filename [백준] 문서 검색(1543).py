docu = input()
word = input()
answer = 0
while True:
    index = docu.find(word)
    if index == -1:
        break
    docu = docu[:index] + '-' + docu[index+len(word):]
    answer += 1
print(answer)
