import sys
sys.setrecursionlimit(10**6)

num = input()

def transfrom(n, ans):
    if len(n) < 2:
        if int(n)%3 != 0:
            ans[0] = "NO"
        return

    nxt = 0
    for i in n:
        nxt += int(i)

    ans[1] += 1
    transfrom(str(nxt), ans)

    return

answer = ["YES", 0]
transfrom(num, answer)
print(answer[1])
print(answer[0])