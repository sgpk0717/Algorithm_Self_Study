def is_valid(n):
    if n>100000: return False
    if n<0: return False
    if visited[n]: return False
    return True

N, K = map(int,input().split())

visited = [False for _ in range(100001)]
founded = False
cnt=0
answer=0
queue = []
visited[N] = True
queue.append(N)


while not founded:
    next_targets = list(queue)
    queue.clear()
    for i in range(len(next_targets)):
        cur = next_targets[i]
        if cur == K:
            founded = True
            answer = cnt
            break
        if is_valid(cur-1):
            visited[cur-1] = True
            queue.append(cur-1)
        if is_valid(cur+1):
            visited[cur+1] = True
            queue.append(cur+1)
        if is_valid(cur*2):
            visited[cur*2] = True
            queue.append(cur*2)
    cnt += 1
print(answer)
