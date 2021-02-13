def is_palin(num):
    num = str(num)
    i=0
    j=len(num)-1
    while i < j:
        if num[i] != num[j]: return False
        i += 1
        j -= 1
    return True

def is_prime(num):
    for i in range(2,int(num**0.5)+1):
        if num % i == 0:
            # print(i,'로 나누어 떨어짐.')
            return False
    return True

N = int(input())
if N == 1: N += 1
answer = 0
while True:
    # print(N)
    if is_palin(str(N)):
        # print("it's palin.")
        if is_prime(N):
            # print("it's prime")
            answer = N
            break
    N += 1
print(answer)