N = int(input())
network = [[] for _ in range(N+1)]
E = int(input())
for i in range(E):
    s,e = map(int,input().split())
    network[s].append(e)
    network[e].append(s)

visited = [False for _ in range(N+1)]

queue = []
queue.append(1)
visited[1] = True
infected = 0

while queue:
    target = queue.pop(0)
    connected = network[target]
    for i in range(len(connected)):
        if not visited[connected[i]]:
            visited[connected[i]] = True
            queue.append(connected[i])
            infected += 1

print(infected)

