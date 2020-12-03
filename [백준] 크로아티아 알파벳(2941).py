input_str = [input()]
croatia_alphabets = ['dz=','c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=']
count = 0

def find_target(in_str, target):
    for i in in_str:
        if i.find(target)!=-1:
            return True
    return False

def count_target(in_str, target):
    temp = in_str
    cnt=0
    while temp.find(target)!=-1:
        temp = temp.replace(target,'|',1)
        cnt+=1
    return cnt

for ca in croatia_alphabets:
    target = ca
    while find_target(input_str, target):
        # print('"%s" find'%target)
        # print(input_str)
        for i in reversed(range(len(input_str))):
            if input_str[i].find(target)!=-1:
                count += count_target(input_str[i],target)
                input_str += input_str.pop(i).split(target)

# print('remain:',''.join(input_str))
print(count+len(''.join(input_str)))