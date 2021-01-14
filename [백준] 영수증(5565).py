price_sum = int(input())
prices = []
for i in range(9):
    prices.append(int(input()))
nine_sum = sum(prices)
print(price_sum - nine_sum)