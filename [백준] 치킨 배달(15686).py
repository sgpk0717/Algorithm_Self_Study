from itertools import combinations

def cal_distance(crd1, crd2):
    return abs(crd1[0]-crd2[0])+abs(crd1[1]-crd2[1])

N, M = map(int,input().split())
city = []
for i in range(N):
    city.append(list(map(int,input().split())))
chickens = []
houses = []
for i in range(N):
    for j in range(N):
        if city[i][j] == 1:
            houses.append((i,j))
        elif city[i][j] == 2:
            chickens.append((i,j))
num_house = len(houses)
num_chicken = len(chickens)

# 행이 집, 열이 치킨가게
dist_vector = [[0]*num_house for _ in range(num_chicken)]
for i in range(num_chicken):
    for j in range(num_house):
        dist_vector[i][j] = cal_distance(chickens[i],houses[j])

chickens_index = [i for i in range(num_chicken)]
comb_chicken = list(combinations(chickens_index,M))
min_sum = 99999999999


for i in range(len(comb_chicken)):
    temp_dist_vector = []
    for j in range(len(comb_chicken[i])):
        temp_dist_vector.append(dist_vector[ comb_chicken[i][j] ])

    sum_dist = 0
    for j in range(num_house):
        min_dist = 200
        for k in range(len(temp_dist_vector)):
            if min_dist > temp_dist_vector[k][j]:
                min_dist = temp_dist_vector[k][j]
        sum_dist += min_dist

    if min_sum > sum_dist: min_sum = sum_dist
print(min_sum)