cards = [i for i in range(1,21)]

for _ in range(10):
    interval = input().split()
    a, b = int(interval[0])-1, int(interval[1])

    cards[a:b] = reversed(cards[a:b])

for c in cards:
    print(c, end=' ')