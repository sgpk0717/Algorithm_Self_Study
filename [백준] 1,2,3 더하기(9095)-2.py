comb = [0 for _ in range(12)]

comb[1]=1
comb[2]=2
comb[3]=4

for i in range(4, len(comb)):
    comb[i] = comb[i-3] + comb[i-2] + comb[i-1]

T = int(input())
for test_case in range(1,T+1):
    N = int(input())
    print(comb[N])