answer1 = [1,2,3,4,5]
answer2 = [2,1,2,3,2,4,2,5]
answer3 = [3,3,1,1,2,2,4,4,5,5]
result = []

def solution(results):
    result = results
    results = []

    results.append((1,getScore(answer1,result)))
    results.append((2,getScore(answer2,result)))
    results.append((3,getScore(answer3,result)))

    sorted(sorted(results, key = lambda results : results[0], reverse=True), key = lambda results : results[1], reverse=True)
    
    temp = results[0][1]
    final = []
    final.append(results[0][0])

    for i in range (1,3):
        if temp == results[i][1]:
            final.append(results[i][0])

    print(final)
    return final

def getScore(answer, result):
    score = 0
    length = 0

    if len(answer) <= len(result) :
        length = len(answer)
    else :
        length = len(result)
    
    for i in range(0, length):
        if answer[i] == result[i]:
            score += 1
    return score

solution([1,3,2,4,2])