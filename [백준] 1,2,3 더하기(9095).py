def make_comb_list(cur_list, sum, N):
    if sum > N: return
    if sum == N:
        comb_list.append(list(cur_list))

    cur_list.append(1)
    make_comb_list(cur_list, sum + 1, N)
    cur_list.pop(-1)

    cur_list.append(2)
    make_comb_list(cur_list, sum + 2, N)
    cur_list.pop(-1)

    cur_list.append(3)
    make_comb_list(cur_list, sum + 3, N)
    cur_list.pop(-1)


T = int(input())

for test_case in range(1, T+1):
    N = int(input())

    comb_list = []
    make_comb_list([],0,N)

    print(len(comb_list))
