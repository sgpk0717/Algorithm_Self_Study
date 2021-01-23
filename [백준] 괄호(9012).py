T = int(input())
for test_case in range(T):
    string = input()

    score = 0
    for s in string:
        if s == '(': score += 1
        else: score -= 1
        if score < 0: break
    if score != 0:
        print('NO')
    else:
        print('YES')
