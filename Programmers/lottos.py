def solution(lottos, win_nums):
    lottos.sort(reverse = True)
    zero = lottos.count(0)

    match = 0 
    for i in range(0, len(lottos) if zero == 0 else lottos.index(0)):
        if lottos[i] in win_nums:
            match += 1

    print([getScore(match + zero), getScore(match)])
    return [getScore(match + zero), getScore(match)]

def getScore(match):
    if match < 2 : 
        return 6
    else :
        return 7 - match

solution([45, 4, 35, 20, 3, 9], [20, 9, 3, 45, 4, 35])
