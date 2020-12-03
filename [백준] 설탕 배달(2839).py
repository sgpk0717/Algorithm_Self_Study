def solution(total_sugar):
    sugar_5g = total_sugar // 5

    for s5 in reversed(range(0, sugar_5g + 1)):
        remain_sugar = total_sugar - s5 * 5
        if remain_sugar % 3 == 0:
            return s5 + remain_sugar//3
    return -1

N = int(input())
print(solution(N))
