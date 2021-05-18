T = int(input())

for test_case in range(T):
    Y_sum = 0
    K_sum = 0

    for i in range(9):
        y, k = map(int,input().split())
        Y_sum += y
        K_sum += k

    if Y_sum > K_sum:
        print('Yonsei')
    elif Y_sum < K_sum:
        print("Korea")
    else:
        print("Draw")