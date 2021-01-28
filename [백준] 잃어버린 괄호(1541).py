expressions = input()
exp = []

s,e = 0,0
while e < len(expressions):
    if expressions[e] == '-' or expressions[e] == '+':
        exp.append(int(expressions[s:e]))
        exp.append(expressions[e])
        s = e + 1
    e += 1
exp.append(int(expressions[s:e]))

ans = exp[0]
minus_flag = False
for i in range(1,len(exp)):
    if exp[i] == '-':
        minus_flag = True
    if exp[i] == '-' or exp[i] == '+':
        if minus_flag:
            ans -= exp[i+1]
        else:
            ans += exp[i+1]
print(ans)
