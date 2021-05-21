N = int(input())

t = 0
num = 1
while N > 0:
    if num > N:
        num = 1
        continue
    N -= num
    num += 1
    t += 1
print(t)