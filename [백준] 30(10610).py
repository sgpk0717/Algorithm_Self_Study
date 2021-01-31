N = [int(i) for i in input()]
if sum(N) % 3 != 0 or not 0 in N:
    print(-1)
else:
    print(int(''.join(map(str,sorted(N,reverse=True)))))