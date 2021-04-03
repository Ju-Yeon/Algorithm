board = [[0 for col in range(100)] for row in range(100)]
dx = [+1, 0, -1, 0]
dy = [0, -1, 0, +1]

def solution(rows, columns, queries):
    answer = []
    num = 1
    for y in range(rows):
        for x in range(columns):
            board[y][x] = num
            num += 1
    
    for i in queries:
        sY = i[0] - 1
        sX = i[1] - 1
        eY = i[2] - 1
        eX = i[3] - 1
        answer.append(rotate(sY, sX, eY, eX))
        
    print (answer)
    return answer

def rotate(sY, sX, eY, eX):
    arr = []
    x = sX
    y = sY
    
    while x < eX:
        arr.append(board[y][x])
        x += 1
    while y < eY:
        arr.append(board[y][x])
        y += 1
    while x > sX:
        arr.append(board[y][x])
        x -= 1
    while y > sY:
        arr.append(board[y][x])
        y -= 1

    x = sX
    y = sY
    arr = arr[-1:] + arr[:-1]

    i = 0
    while x < eX:
        board[y][x] = arr[i]
        x += 1
        i += 1
    while y < eY:
        board[y][x] = arr[i]
        y += 1
        i += 1
    while x > sX:
        board[y][x] = arr[i]
        x -= 1
        i += 1
    while y > sY:
        board[y][x] = arr[i]
        y -= 1
        i += 1
    arr.sort()
    return arr[0]


#solution(6,6,[[2,2,5,4],[3,3,6,6],[5,1,6,3]]) #[8,10,25]
#solution(3,3,[[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]) #[1,1,5,3]
solution(100,97,[[1,1,100,97]]) #[1]