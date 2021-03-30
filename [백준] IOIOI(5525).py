N = int(input())
M = int(input())
S = input()

def check_pattern_match(idx, s, pattern):
    for i in range(len(pattern)):
        if s[idx+i] != pattern[i]:
            return idx+i
    return idx+len(pattern)

def check_additional_pattern(idx, s):
    while idx + 2 < len(s):
        if s[idx] == 'O' and s[idx+1] == 'I':
            idx += 2
        else:
            break
    return idx

pattern = 'I' + 'OI'*N
idx = 0
answer = 0
while idx+len(pattern) <= M:
    if S[idx] == 'I':
        ret_idx = check_pattern_match(idx,S,pattern)
        if ret_idx == idx + len(pattern):
            add_idx = check_additional_pattern(ret_idx,S)
            answer += 1 + ((add_idx - ret_idx) // 2)
            idx = add_idx
        else:
            idx = ret_idx
    else:
        idx += 1
print(answer)