
# k번째수 https://www.welcomekakao.com/learn/courses/30/lessons/42748

def solution(array, commands):
    answer=[]
    _len=len(commands)
    for i in range(_len):
        temp=array[(commands[i][0]-1):commands[i][1]]
        temp.sort()
        answer.append(temp[(commands[i][2]-1)])
    return answer


'''def solution(array, commands):
    answer = []
    for command in commands:
        i,j,k = command
        answer.append(list(sorted(array[i-1:j]))[k-1])
    return answer'''
