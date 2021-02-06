A, B = input().split()
min_diff = 99
for i in range(len(B)):
    if i + len(A) > len(B):
        break

    diff = 0
    for j in range(len(A)):
        if B[i+j] != A[j]:
            diff += 1
    min_diff = min(diff, min_diff)
print(min_diff)