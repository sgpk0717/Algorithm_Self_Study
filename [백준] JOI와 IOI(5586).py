def get_IOI(str,idx):
    cnt = 0
    while idx < len(str) - 2:
        if str[idx+1:idx+3] == 'OI':
            cnt += 1
            idx += 2
        else:
            break
    return cnt

input_str = input()
idx = 0
num_JOI = 0
num_IOI = 0
while idx < len(input_str):
    if input_str[idx] == 'J':
        if idx + 2 < len(input_str):
            if input_str[idx+1:idx+3] == 'OI':
                num_JOI += 1
                idx += 2
            else:
                idx += 1
        else:
            idx += 1
    elif input_str[idx] == 'I':
        cnt = get_IOI(input_str,idx)
        num_IOI += cnt
        idx += (2*cnt)+1
    else:
        idx += 1
print(num_JOI)
print(num_IOI)