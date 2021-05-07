univs = list(map(int, input().split()))

min_work = 111
min_univ = -1
sum_work = 0
for i in range(3):
    sum_work += univs[i]
    if min_work > univs[i]:
        min_work = univs[i]
        min_univ = i

if sum_work >= 100:
    print("OK")
else:
    if min_univ == 0:
        print("Soongsil")
    elif min_univ == 1:
        print("Korea")
    else:
        print("Hanyang")