N = int(input())
scores = input().split()

score_sum = 0
scsv = 0
for i in range(len(scores)):
    if scores[i] == '0':
        scsv = 0
    elif scores[i] == '1':
        scsv += 1
        score_sum += (int(scores[i]) * scsv)
print(score_sum)