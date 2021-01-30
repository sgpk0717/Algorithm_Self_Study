import sys

while True:
    inputs = sys.stdin.readline().rstrip('\n')
    if inputs == '.': break

    balanced = True
    queue = []
    for i in range(len(inputs)):
        if inputs[i] == '(' or inputs[i] == '[':
            queue.append(inputs[i])
        elif inputs[i] == ')':
            if len(queue) == 0:
                balanced = False
                break
            if queue[-1] == '(':
                queue.pop(-1)
            else:
                balanced = False
                break
        elif inputs[i] == ']':
            if len(queue) == 0:
                balanced = False
                break
            if queue[-1] == '[':
                queue.pop(-1)
            else:
                balanced = False
                break

    if balanced and len(queue) == 0:
        print('yes')
    else:
        print('no')