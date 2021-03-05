from collections import defaultdict
dt = defaultdict(int)
S = input()
for i in range(len(S)):
    for j in range(i+1,len(S)+1):
        dt[S[i:j]] += 1
print(len(dt.keys()))