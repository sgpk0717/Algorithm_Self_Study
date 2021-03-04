import sys

def find_target(arr, target):
    low = 0
    high = len(arr)-1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] < target:
            low = mid + 1
        elif arr[mid] == target:
            return True
        elif arr[mid] > target:
            high = mid - 1
    return False

N = int(input())
Ns = list(map(int,sys.stdin.readline().split()))
Ns.sort()

M = int(input())
Ms = list(map(int,sys.stdin.readline().split()))

for n in Ms:
    if find_target(Ns,n):
        print(1,end=' ')
    else:
        print(0,end=' ')
print()