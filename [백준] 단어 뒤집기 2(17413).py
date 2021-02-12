import sys
S = [_ for _ in sys.stdin.readline().rstrip()]

begin = 0
i = 0
while i < len(S):
    if S[i] == '<':
        begin = i
        while S[i] != '>': i += 1
        i += 1
        print(''.join(S[begin:i]),end='')
    elif S[i] == ' ':
        print(' ',end='')
        i += 1
    else:
        begin = i
        while i < len(S) and S[i] != ' ' and S[i] != '<': i += 1
        print(''.join(reversed(S[begin:i])),end='')
