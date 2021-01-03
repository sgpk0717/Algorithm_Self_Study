D = input()
numbers = list(input().split())
cnt=0
for num in numbers:
    if num == D:
        cnt+=1
print(cnt)