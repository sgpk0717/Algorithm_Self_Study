X=int(input())
cnt=0
length=1
dir=1
while cnt < X:
    cnt+=length
    length+=1
    dir*=-1
diff = cnt-X
sum = length+1
son=-1
mom=-1
if dir==-1:
    son = 1+diff
    mom = sum-diff-2
else:
    son = sum-diff-2
    mom = 1+diff
print('%d/%d'%(son,mom))
