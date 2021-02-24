import sys

N = int(input())
people = [[] for _ in range(201)]

while N > 0:
    age, name = sys.stdin.readline().rstrip().split()
    people[int(age)].append(name)
    N -= 1

for i in range(1,len(people)):
    for j in range(len(people[i])):
        print(i,people[i][j])