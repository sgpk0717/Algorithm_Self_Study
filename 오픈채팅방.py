def solution(record):
    answer = []
    splited_record=[]
    nickname_list = {}

    for i in range(len(record)):
        splited_record.append(record[i].split(' '))
        if splited_record[i][0]!='Leave':
            nickname_list[splited_record[i][1]] = splited_record[i][2]

    for i in range(len(splited_record)):
        if splited_record[i][0]=='Change':
            continue

        if splited_record[i][0]=='Enter':
            answer.append("%s님이 들어왔습니다."%nickname_list[splited_record[i][1]])
        elif splited_record[i][0]=='Leave':
            answer.append("%s님이 나갔습니다."%nickname_list[splited_record[i][1]])

    return answer