from collections import defaultdict

def dfs(current_list, remain_trade, dict):
    if remain_trade==0:
        return int(''.join(current_list))
    if(dict[(''.join(current_list),remain_trade)]!=0):
        return dict[(''.join(current_list),remain_trade)]

    max_retv=-1
    for i in range(len(current_list)):
        for j in range(i+1,len(current_list)):
            temp_list = [] + current_list
            temp_list[i], temp_list[j] = temp_list[j], temp_list[i]
            retv = dfs(temp_list, remain_trade-1, dict)
            if max_retv < retv:
                max_retv = retv
    dict[(''.join(current_list),remain_trade)] = max_retv
    return max_retv

T = int(input())
for test_case in range(1, T + 1):
    dict = defaultdict(int)
    numbers, trade = input().split()
    numbers = list(numbers)
    trade = int(trade)

    for i in range(1,trade+1):
        dfs(numbers,i,dict)
    print('#%d'%test_case,dict[''.join(numbers),trade])

