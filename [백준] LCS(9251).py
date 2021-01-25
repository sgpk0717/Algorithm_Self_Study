str1 = input()
str2 = input()
len_str1 = len(str1)
len_str2 = len(str2)

board = [[0]*(len_str1+1)for _ in range(len_str2+1)]

for i in range(1,len(board)):
    for j in range(1,len(board[i])):
        if str2[i-1]==str1[j-1]:
            board[i][j] = board[i-1][j-1]+1
        else:
            board[i][j] = max(board[i][j-1],board[i-1][j])

# for b in board:
#     print(b)
# print()

print(board[-1][-1])