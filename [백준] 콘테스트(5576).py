W = []
K = []

for i in range(10):
    W.append(int(input()))

for i in range(10):
    K.append(int(input()))

W.sort()
K.sort()

print(sum(W[-3:]),sum(K[-3:]))