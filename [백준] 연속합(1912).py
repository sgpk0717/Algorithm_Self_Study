N = int(input())
numbers = list(map(int,input().split()))
max_result=numbers[0]
for i in range(1,N):
    numbers[i] = max(numbers[i-1]+numbers[i], numbers[i])
    max_result = max(max_result,numbers[i])
print(max_result)