def time_to_int(str):
    retv = 0
    temp = str.split(':')
    retv += int(float(temp[2])*1000)
    retv += int(temp[1])*60*1000
    retv += int(temp[0])*60*60*1000
    return retv

def sec_to_int(str):
    return int(float(str[:-1])*1000)

def solution(lines):
    answer = 0
    times=[]
    for line in lines:
        time = line.split(' ')[1:]
        time[0] = time_to_int(time[0])
        time[1] = sec_to_int(time[1])
        times.append(time)

    return answer