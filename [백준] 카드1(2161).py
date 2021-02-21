N = int(input())
cards = [_ for _ in range(1, N+1)]

while len(cards) > 1:
    print(cards.pop(0),end=' ')
    tmp = cards.pop(0)
    cards.append(tmp)
print(cards[0])