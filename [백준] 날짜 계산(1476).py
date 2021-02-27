E, S, M = map(int,input().split())

answer = 1
while True:
    if E == 1 and S == 1 and M == 1: break
    # print(E, S, M)
    E = ((E - 2) % 15) + 1
    S = ((S - 2) % 28) + 1
    M = ((M - 2) % 19) + 1
    answer += 1
print(answer)
