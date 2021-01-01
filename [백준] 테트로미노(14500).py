N, M = map(int, input().split())
arr = [];
x = []
for _ in range(N):
    arr.append(list(map(int, input().split())))

answer = []
for i in range(N):

    for k in range(M):
        # k = 0 1 2 3 4 / M = 5
        # 일자 - 가로
        if k + 3 < M:
            x.append(arr[i][k] + arr[i][k + 1] + arr[i][k + 2] + arr[i][k + 3])
        # 일자 - 세로
        if i + 3 < N:
            x.append(arr[i][k] + arr[i + 1][k] + arr[i + 2][k] + arr[i + 3][k])

        # 정사각형
        if k + 1 < M and i + 1 < N:
            x.append(arr[i][k] + arr[i][k + 1] + arr[i + 1][k] + arr[i + 1][k + 1])

        # ㅗ모양
        if k + 2 < M and i + 1 < N:
            x.append(arr[i][k + 1] + arr[i + 1][k] + arr[i + 1][k + 1] + arr[i + 1][k + 2])
        # ㅜ모양
        if k + 2 < M and i + 1 < N:
            x.append(arr[i + 1][k + 1] + arr[i][k] + arr[i][k + 1] + arr[i][k + 2])
            # ㅓ모양
        if k + 1 < M and i + 2 < N:
            x.append(arr[i + 1][k] + arr[i][k + 1] + arr[i + 1][k + 1] + arr[i + 2][k + 1])
            # ㅏ 모양
        if k + 1 < M and i + 2 < N:
            x.append(arr[i + 1][k + 1] + arr[i][k] + arr[i + 1][k] + arr[i + 2][k])

            ##
        #
        # 모양
        if k + 1 < M and i + 2 < N:
            x.append(arr[i][k] + arr[i][k + 1] + arr[i + 1][k + 1] + arr[i + 2][k + 1])
        ##
        #
        #  모양
        if k + 1 < M and i + 2 < N:
            x.append(arr[i][k] + arr[i][k + 1] + arr[i + 1][k] + arr[i + 2][k])

        #
        #
        ## 모양
        if k + 1 < M and i + 2 < N:
            x.append(arr[i][k] + arr[i + 1][k] + arr[i + 2][k] + arr[i + 2][k + 1])
        #
        #
        ## 모양
        if k + 1 < M and i + 2 < N:
            x.append(arr[i + 2][k] + arr[i][k + 1] + arr[i + 1][k + 1] + arr[i + 2][k + 1])
        ###
        #   모양
        if k + 2 < M and i + 1 < N:
            x.append(arr[i][k] + arr[i][k + 1] + arr[i][k + 2] + arr[i + 1][k])
        #
        ### 모양
        if k + 2 < M and i + 1 < N:
            x.append(arr[i][k + 2] + arr[i + 1][k] + arr[i + 1][k + 1] + arr[i + 1][k + 2])

        #
        ### 모양
        if k + 2 < M and i + 1 < N:
            x.append(arr[i][k] + arr[i + 1][k] + arr[i + 1][k + 1] + arr[i + 1][k + 2])

        ###
        # 모양
        if k + 2 < M and i + 1 < N:
            x.append(arr[i][k] + arr[i][k + 1] + arr[i][k + 2] + arr[i + 1][k + 2])
        ###
        #    모양
        if k + 2 < M and i + 1 < N:
            x.append(arr[i][k] + arr[i][k + 1] + arr[i][k + 2] + arr[i + 1][k])

        #
        ##
        # 모양
        if k + 1 < M and i + 2 < N:
            x.append(arr[i][k] + arr[i + 1][k] + arr[i + 1][k + 1] + arr[i + 2][k + 1])
        #
        ##
        #
        if k + 1 < M and i + 2 < N:
            x.append(arr[i][k + 1] + arr[i + 1][k] + arr[i + 1][k + 1] + arr[i + 2][k])

        ##
        ##
        if k + 2 < M and i + 1 < N:
            x.append(arr[i][k] + arr[i][k + 1] + arr[i + 1][k + 1] + arr[i + 1][k + 2])
        ##
        ##
        if k + 2 < M and i + 1 < N:
            x.append(arr[i][k + 1] + arr[i][k + 2] + arr[i + 1][k] + arr[i + 1][k + 1])
print(max(x))