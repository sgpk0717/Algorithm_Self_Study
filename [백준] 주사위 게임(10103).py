N = int(input())

ch = 100
sa = 100
for i in range(N):
    chang, sang = map(int,input().split())
    if chang < sang:
        ch -= sang
    elif chang > sang:
        sa -= chang
print(ch)
print(sa)