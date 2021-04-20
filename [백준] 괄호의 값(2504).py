from collections import deque

def test_valid(braces):
    stack = deque()
    for i in range(len(braces)):
        if braces[i] == '(' or braces[i] == '[':
            stack.append(braces[i])
        elif braces[i] == ')':
            if len(stack) == 0: return False
            if stack[-1] != '(':
                return False
            stack.pop()
        elif braces[i] == ']':
            if len(stack) == 0: return False
            if stack[-1] != '[':
                return False
            stack.pop()
    if len(stack) != 0:
        return False
    return True

def cal_expr(braces):
    if len(braces) == 0:
        return 1

    retv = 0
    stack = deque()
    s, e = 0, 0
    for i in range(len(braces)):
        if braces[i] == '(' or braces[i] == '[':
            stack.append(braces[i])
        elif braces[i] == ')':
            if stack[-1] != '(':
                return False
            stack.pop()
        elif braces[i] == ']':
            if stack[-1] != '[':
                return False
            stack.pop()

        if len(stack) == 0:
            e = i+1
            if braces[s] == '(':
                retv += 2 * cal_expr(braces[s+1:e-1])
            else:
                retv += 3 * cal_expr(braces[s+1:e-1])
            s = e
    return retv


braces = input()
if not test_valid(braces):
    print('0')
else:
    print(cal_expr(braces))