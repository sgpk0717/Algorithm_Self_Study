from collections import defaultdict

def is_possible(dt):
    odd_cnt = 0
    odd_char = ''
    for k, v in dt.items():
        if v % 2 != 0:
            odd_char = k
            odd_cnt += 1
            if odd_cnt > 1:
                return False, '#'
    return True, odd_char

def solution(name):
    dt = defaultdict(int)
    for c in name:
        dt[c] += 1

    possible, odd_char = is_possible(dt)
    if not possible:
        return "I'm Sorry Hansoo"

    rets = ''
    keys = list(dt.keys())
    keys.sort()
    for k in keys:
        for i in range(dt[k]//2):
            rets += k

    rrets = rets[::-1]
    if odd_char != '':
        rets += odd_char
    rets += rrets
    return rets


name = input()
print(solution(name))