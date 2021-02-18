T = int(input())

for test_case in range(T):
    n, k = map(int,input().split())

    if n % 2 == 0:
        print(((k - 1) % n) + 1)
    else:
        print(((k - 1 + (k-1)//(n//2)) % n) + 1)