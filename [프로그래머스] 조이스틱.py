def move_horizontal(current_pos, current_name, target_name):
    for i in range(1, len(current_name) // 2 + 1):
        target_pos = (current_pos+i)%len(current_name)
        if current_name[target_pos] != target_name[target_pos]: return i

        if current_pos - i < 0: target_pos = current_pos+len(current_name)-i
        else: target_pos = current_pos - i

        if current_name[target_pos] != target_name[target_pos]: return -i

def move_vertical(target_chr):
    current_ascii = ord('A')
    target_ascii = ord(target_chr)
    return min(target_ascii - current_ascii, current_ascii + 26 - target_ascii)

def solution(name):
    answer = 0
    target_name = list(name)
    current_name = ['A' for _ in range(len(name))]
    current_idx = 0
    answer += move_vertical(target_name[current_idx])
    current_name[current_idx] = target_name[current_idx]

    while current_name != target_name:
        move_horizon = move_horizontal(current_idx, current_name, target_name)
        if move_horizon >= 0:
            answer += move_horizon
            current_idx = (current_idx + move_horizon)%len(current_name)
        else:
            answer -= move_horizon
            if current_idx + move_horizon < 0:
                current_idx = current_idx + len(current_name) + move_horizon
            else:
                current_idx = current_idx + move_horizon
        move_vert = move_vertical(target_name[current_idx])
        answer += move_vert
        current_name[current_idx] = target_name[current_idx]
    return answer