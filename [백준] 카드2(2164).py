N = int(input())
cards = [_ for _ in range(1,N+1)]
len_cards = N

while len_cards > 1:
    len_cards -= 1
    cards.append(cards[len(cards)-len_cards])
print(cards[len(cards)-len_cards])