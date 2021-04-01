import sys

def cal_expression(numbers):
    retv = numbers[0]
    for i in range(len(op_set)):
        if op_set[i] == '+':
            retv += numbers[i+1]
        elif op_set[i] == '-':
            retv -= numbers[i+1]
        elif op_set[i] == 'x':
            retv *= numbers[i+1]
        else:
            if retv < 0:
                retv = -retv
                retv //= numbers[i+1]
                retv = -retv
            else:
                retv //= numbers[i+1]
    return retv

def get_min_max_by_dfs(plus_cnt, minus_cnt, multi_cnt, div_cnt):
    if len(op_set) == N-1:
        result = cal_expression(numbers)
        answers[0] = min(answers[0], result)
        answers[1] = max(answers[1], result)
        return

    if plus_cnt != 0:
        op_set.append('+')
        get_min_max_by_dfs(plus_cnt - 1, minus_cnt, multi_cnt, div_cnt)
        op_set.pop(-1)
    if minus_cnt != 0:
        op_set.append('-')
        get_min_max_by_dfs(plus_cnt, minus_cnt - 1, multi_cnt, div_cnt)
        op_set.pop(-1)
    if multi_cnt != 0:
        op_set.append('x')
        get_min_max_by_dfs(plus_cnt, minus_cnt, multi_cnt - 1, div_cnt)
        op_set.pop(-1)
    if div_cnt != 0:
        op_set.append('/')
        get_min_max_by_dfs(plus_cnt, minus_cnt, multi_cnt, div_cnt - 1)
        op_set.pop(-1)

input = sys.stdin.readline

N = int(input())
numbers = [int(i) for i in input().rstrip().split()]
op_num = list(map(int,input().rstrip().split()))
op_set = []
answers = [1000000001,-1000000001]
get_min_max_by_dfs(op_num[0],op_num[1],op_num[2],op_num[3])
print(answers[1])
print(answers[0])