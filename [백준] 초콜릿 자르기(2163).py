N, M = map(int,input().split())
longer = max(N,M)
shorter = min(N,M)
print(shorter-1 + (longer-1)*shorter)