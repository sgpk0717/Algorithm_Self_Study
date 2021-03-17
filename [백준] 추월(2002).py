import sys

def find_closest_false(check_exceed, cur):
    for i in range(cur+1,len(check_exceed)):
        if not check_exceed[i]:
            return i

N = int(input())

car_in = {}
for i in range(N):
    car_in[sys.stdin.readline().rstrip()] = i

target = 0
answer = 0
check_exceed = [False for _ in range(N)]
for i in range(N):
    car_number = sys.stdin.readline().rstrip()
    if car_in[car_number] == target:
        # print('target found!')
        # print('car_number: %s, in: %d, out: %d'%(car_number, car_in[car_number],i))
        target = find_closest_false(check_exceed, target)
    else:
        check_exceed[car_in[car_number]] = True
        answer += 1
print(answer)