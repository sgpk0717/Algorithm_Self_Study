people = []
for i in range(4):
    people.append(list(map(int,input().split())))
remains=0
max_remains=0
for i in range(4):
    remains = remains + people[i][1]-people[i][0]
    if remains > max_remains:
        max_remains = remains
print(max_remains)