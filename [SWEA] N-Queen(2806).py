def count_case(chess_board,idx,N):
    if idx==N: return 1
    cnt=0
    for i in range(N):
        chess_board[idx] = i
        if is_valid(chess_board, idx):
            cnt += count_case(chess_board,idx+1,N)
    return cnt
def is_valid(chess_board,target_idx):
    if check_diagonal(chess_board,target_idx) and check_horizontal(chess_board,target_idx): return True
    else: return False

def check_diagonal(chess_board,target_idx):
    for i in range(target_idx):
        if abs(chess_board[i]-chess_board[target_idx])==abs(i-target_idx): return
    return True
def check_horizontal(chess_board,target_idx):
    for i in range(target_idx):
        if chess_board[i] == chess_board[target_idx]: return False
    return True

T = int(input())

for test_case in range(1,T+1):
    N = int(input())
    chess_board = [-999 for _ in range(N)]
    print('#%d'%test_case,count_case(chess_board,0,N))
