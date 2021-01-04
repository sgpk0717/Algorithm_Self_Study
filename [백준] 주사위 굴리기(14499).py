class Dice:
    def __init__(self):
        self.up = 0
        self.down = 0
        self.left = 0
        self.right = 0
        self.front = 0
        self.back = 0

    def roll_down(self):
        tmp = self.down
        self.down = self.front
        self.front = self.up
        self.up = self.back
        self.back = tmp

    def roll_up(self):
        tmp = self.down
        self.down = self.back
        self.back = self.up
        self.up = self.front
        self.front = tmp

    def roll_left(self):
        tmp = self.down
        self.down = self.left
        self.left = self.up
        self.up = self.right
        self.right = tmp

    def roll_right(self):
        tmp = self.down
        self.down = self.right
        self.right = self.up
        self.up = self.left
        self.left = tmp

    def get_down(self):
        return self.down

    def get_up(self):
        return self.up

    def set_down(self,down):
        self.down = down

    def print_dice(self):
        print(' ',self.back,' ')
        print(self.left,self.up,self.right)
        print(' ',self.front,' ')
        print(' ',self.down,' ')

def check_boundary(x, y):
    if x < 0 or x >= N: return False
    if y < 0 or y >= M: return False
    return True

N, M, x, y, K = map(int,input().split())
Map = []
for i in range(N):
    Map.append(list(map(int,input().split())))
Orders = list(map(int,input().split()))

cur_x = x
cur_y = y
dice = Dice()
for i in range(K):
    if Orders[i] == 1:
        if check_boundary(x,y+1):
            y+=1
            dice.roll_right()
        else: continue
    elif Orders[i] == 2:
        if check_boundary(x,y-1):
            y-=1
            dice.roll_left()
        else: continue
    elif Orders[i] == 3:
        if check_boundary(x-1,y):
            x-=1
            dice.roll_up()
        else: continue
    else:
        if check_boundary(x+1,y):
            x+=1
            dice.roll_down()
        else: continue

    if Map[x][y] == 0:
        Map[x][y] = dice.get_down()
    else:
        dice.set_down(Map[x][y])
        Map[x][y] = 0
    print(dice.get_up())