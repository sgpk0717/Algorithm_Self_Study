dish = input()

total = 10
for i in range(1,len(dish)):
    if dish[i] == '(':
        if dish[i-1] == '(':
            total += 5
        else:
            total += 10
    else:
        if dish[i-1] == ')':
            total += 5
        else:
            total += 10
print(total)