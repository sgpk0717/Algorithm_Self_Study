from collections import defaultdict

def make_dict(words):
    dict = defaultdict(int)

    for word in words:
        dict['?'*len(word)]+=1
        for i in range(1,len(word)):
            temp = '?'*i
            temp += word[i:]
            dict[temp]+=1

        for i in range(1,len(word)):
            temp = word[:-i]
            temp += '?'*i
            dict[temp]+=1

    return dict


def solution(words, queries):
    answer = []

    dict = make_dict(words)

    for query in queries:
        print(dict.get(query, 0))




words = ['frodo','front','frost','frozen','frame','kakao']
queries = ['fro??','????o','fr???','fro???','pro?']

solution(words, queries)