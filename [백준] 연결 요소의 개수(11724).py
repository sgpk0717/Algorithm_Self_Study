import sys
sys.setrecursionlimit(10**6)


def dfs(n):
    visited[n] = True
    for node in edges[n]:
        if not visited[node]:
            dfs(node)


N,M = map(int,input().split())
visited = [False for _ in range(N+1)]
edges = [[] for _ in range(N+1)]
for _ in range(M):
    s, e = map(int, sys.stdin.readline().split())
    edges[s].append(e)
    edges[e].append(s)
answer=0
for i in range(1,N+1):
    if not visited[i]:
        answer += 1
        dfs(i)
print(answer)