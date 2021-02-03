word1 = [i for i in input()]
word2 = [i for i in input()]
alpha_list1 = [0 for _ in range(26)]
alpha_list2 = [0 for _ in range(26)]

for a in word1:
    alpha_list1[ord(a)-ord('a')] += 1
for a in word2:
    alpha_list2[ord(a)-ord('a')] += 1

same_cnt = 0
for i in range(26):
    same_cnt += min(alpha_list1[i],alpha_list2[i])

answer = sum(alpha_list1)-same_cnt + sum(alpha_list2)-same_cnt
print(answer)