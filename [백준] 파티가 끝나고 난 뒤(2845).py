unit_p, area = map(int, input().split())
news = list(map(int, input().split()))

real_num = unit_p * area
for news_num in news:
    print(news_num-real_num, end=' ')