def is_valid_pos(x, y):
    if x<-5 or x>5 or y<-5 or y>5:
        return False
    return True

def new_way_count(hash_table,prev_x,prev_y,x,y):
    #print('px: %d, py: %d, x: %d, y: %d'%(prev_x,prev_y,x,y))
    key1 = str(prev_x)+str(prev_y)+str(x)+str(y)
    key2 = str(x)+str(y)+str(prev_x)+str(prev_y)

    if hash_table.get(key1)!=None:
        #print('지나간적 있음!')
        return 0

    hash_table[key1] = True
    hash_table[key2] = True
    return 1


def solution(dirs):
    answer = 0
    hash_check = {}

    x = y = 0
    prev_x = x
    prev_y = y
    for i in range(len(dirs)):
        #print('---------------')
        #print('dir: %c'%dirs[i])
        if dirs[i]=='U':
            if is_valid_pos(x,y+1):
                prev_x=x
                prev_y=y
                y+=1
                answer+=new_way_count(hash_check,prev_x,prev_y,x,y)
        elif dirs[i]=='D':
            if is_valid_pos(x,y-1):
                prev_x=x
                prev_y=y
                y-=1
                answer+=new_way_count(hash_check,prev_x,prev_y,x,y)
        elif dirs[i]=='L':
            if is_valid_pos(x-1,y):
                prev_x=x
                prev_y=y
                x-=1
                answer+=new_way_count(hash_check,prev_x,prev_y,x,y)
        elif dirs[i]=='R':
            if is_valid_pos(x+1,y):
                prev_x=x
                prev_y=y
                x+=1
                answer+=new_way_count(hash_check,prev_x,prev_y,x,y)

    print(answer)

    return answer