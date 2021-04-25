def get_part_sum(n):
    s = 0
    while n > 0:
        s += n%10
        n //= 10
    return s

def get_constructor(n):
    for i in range(n+1):
        if i + get_part_sum(i) == n:
            return i
    return 0


N = int(input())
print(get_constructor(N))
