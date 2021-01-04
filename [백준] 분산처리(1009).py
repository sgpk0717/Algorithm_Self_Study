T = int(input())
for i in range(T):
    a, b = map(int,input().split())
    a%=10

    if a == 1 or a == 5 or a == 6:
        print(a)
    elif a == 4 or a == 9:
        if b%2 == 0:
            print((a*a)%10)
        else:
            print(a)
    elif a == 0:
        print(10)
    else:
        if b%4 == 0:
            print(pow(a,4)%10)
        elif b%4 == 1:
            print(pow(a,1)%10)
        elif b%4 == 2:
            print(pow(a,2)%10)
        else:
            print(pow(a,3)%10)