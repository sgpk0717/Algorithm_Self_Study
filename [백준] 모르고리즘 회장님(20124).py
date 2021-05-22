n = int(input())

max_score = 0
winners = []
for _ in range(n):
    data = input().split()
    name, score = data[0], int(data[1])

    if max_score < score:
        max_score = score
        winners.clear()
        winners.append(name)
    elif max_score == score:
        winners.append(name)

winners.sort()
print(winners[0])