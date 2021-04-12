T = int(input())
for case in range(T):
    S = input()
    s = 0
    for num in range(65,65+26):
        if not chr(num) in S:
            s += num
    print(s)