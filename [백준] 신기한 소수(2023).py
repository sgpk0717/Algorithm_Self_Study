def is_prime(n):
    if n==0: return False
    if n==1: return False
    for i in range(2,int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def get_amazings(n):
    if n > int('1'+'0'*(N-1)):
        amazings.append(n)
        return

    for i in range(10):
        if is_prime(n*10+i):
            get_amazings(n*10+i)

N = int(input())
amazings = []
get_amazings(0)

for n in amazings:
    print(n)