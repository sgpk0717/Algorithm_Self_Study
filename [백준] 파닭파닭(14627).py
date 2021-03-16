import sys

def is_possible(target, pas):
    remain = 0
    num_pa = 0
    for i in range(len(pas)):
        num_pa += (pas[i]//target)
        remain += (pas[i]%target)
    return num_pa, remain

S, C = map(int,input().split())
pas = []

for i in range(S):
    pas.append(int(sys.stdin.readline().rstrip()))

pas.sort()

low = 1
high = pas[-1]
pa_for_ramen = 0
pa_for_chick = 0

while low <= high:
    mid = (low + high) // 2
    if mid == 0:
        break
    for_chicken, for_ramen = is_possible(mid,pas)

    # print('------------------')
    # print('low: %d, high: %d, mid: %d'%(low,high,mid))

    if for_chicken >= C:
        # print('possible, for_ramen: %d'%for_ramen)
        pa_for_ramen = for_ramen + (for_chicken-C)*mid
        low = mid + 1
    else:
        high = mid - 1
print(pa_for_ramen)