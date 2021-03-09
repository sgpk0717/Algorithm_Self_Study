S = int(input())

s = 0
v = 1
while s + v <= S:
    s += v
    v += 1
print(v-1)