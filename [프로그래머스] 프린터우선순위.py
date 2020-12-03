def get_larger_value_cnt(my_list, target):
    cnt = 0
    for i in my_list:
        if i > target:
            cnt+=1
    return cnt

def get_index_leftmost_value(my_list, target):
    cnt=0

    for i in range(len(my_list)):
        if my_list[i]==target:
            cnt+=1

    return cnt


def get_lower_bound(my_list, target):
    if max(my_list)==target:
        return -1, -1

    lb_value=9999
    lb_index=-1
    for i in range(len(my_list)):
        if my_list[i] > target:
            if my_list[i] <= lb_value:
                lb_value = my_list[i]
                lb_index = i

    return lb_value, lb_index

def remove_priorities(target_priority, my_list):
    return [value for value in my_list if value<=target_priority+1]

def solution(priorities, location):
    answer = 1
    target_priority = priorities[location]

    lb_value, lb_index = get_lower_bound(priorities, target_priority)

    if lb_index==-1:
        print('제일 큼.')
        answer = get_index_leftmost_value(priorities, target_priority)
    else:
        print('제일 크진 않음.')
        idx = lb_index+1
        for i in range(len(priorities)):
            if idx==location:
                break
            if priorities[idx]==target_priority:
                answer+=1

            idx+=1
            idx%=len(priorities)
        answer+=get_larger_value_cnt(priorities,target_priority)

    return answer

pr = [2, 1, 3, 2]
pr2 = [1, 1, 9, 1, 1, 1]

print(solution(pr, 2))
print(solution(pr2,0))