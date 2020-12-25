import math
num = input()
num_counts=[0 for _ in range(10)]
for i in range(len(num)):
    num_counts[ord(num[i])-ord('0')]+=1
# print(num_counts)
max_set=0
for i in range(len(num_counts)):
    if i==6 or i==9: continue
    if num_counts[i] > max_set:
        max_set = num_counts[i]

# print(math.ceil((num_counts[6]+num_counts[9])/2))
if math.ceil((num_counts[6]+num_counts[9])/2) > max_set:
    max_set = math.ceil((num_counts[6]+num_counts[9])/2)
print(max_set)