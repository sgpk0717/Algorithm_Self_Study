import sys

n = int(input())

log = {}
for i in range(n):
    name, action = sys.stdin.readline().rstrip().split()
    if action == 'enter':
        log[name] = 1
    elif action == 'leave':
        log[name] = 0

worker = []
for k, v in log.items():
    if v == 1:
        worker.append(k)
worker.sort(reverse=True)

for w in worker:
    print(w)