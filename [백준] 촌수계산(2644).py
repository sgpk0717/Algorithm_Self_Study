def dfs(c, e, cnt, visited, relations):
    # print('=====================================')
    # print(c,e,cnt,visited)

    if c == e:
        global answer
        answer = cnt
        return

    for i in range(len(relations[c])):
        next = relations[c][i]
        if not visited[next]:
            visited[next] = True
            dfs(next, e, cnt+1, visited, relations)
            visited[next] = False


n = int(input())
targets = list(map(int,input().split()))
m = int(input())
answer = -1

relations = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]

for i in range(m):
    s, e = map(int,input().split())
    relations[s].append(e)
    relations[e].append(s)

dfs(targets[0],targets[1],0,visited,relations)
print(answer)
