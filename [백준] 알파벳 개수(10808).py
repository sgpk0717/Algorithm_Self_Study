counts = [0 for _ in range(26)]
input_str = input()
for c in input_str:
    counts[ord(c)-ord('a')]+=1
for i in counts:
    print(i,end=' ')