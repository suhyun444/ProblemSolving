dirY = [-1,-1,-1,0,1,1,1,0]
dirX = [-1,0,1,1,1,0,-1,-1]
knightDirY = [-1,-2,-2,-1,1,2,2,1]
knightDirX = [-2,-1,1,2,2,1,-1,-2]
n,m = map(int,input().split(' '))
queen = list(map(int,input().split(' ')))
knignt = list(map(int,input().split(' ')))
pawn = list(map(int,input().split(' ')))
board = [[0 for j in range(m + 1)]for i in range(n + 1)]
for i in range(pawn[0]):
    board[pawn[i*2+1]][pawn[i*2+2]] = 2
for i in range(queen[0]):
    board[queen[i*2+1]][queen[i*2+2]] = 2
for i in range(knignt[0]):
    board[knignt[i*2+1]][knignt[i*2+2]] = 2


for i in range(queen[0]):
    y = queen[i*2+1]
    x = queen[i*2+2]
    for j in range(8):
        size = 1
        while True:
            nextY = y + dirY[j] * size
            nextX = x + dirX[j] * size
            if nextY <= 0 or nextY > n or nextX <= 0 or nextX > m or board[nextY][nextX] == 2:
                break
            board[nextY][nextX] = 1
            size += 1

for i in range(knignt[0]):
    y = knignt[i*2+1]
    x = knignt[i*2+2]
    for j in range(8):
        nextY = y + knightDirY[j]
        nextX = x + knightDirX[j]
        if nextY <= 0 or nextY > n or nextX <= 0 or nextX > m or board[nextY][nextX] == 2:
            continue
        board[nextY][nextX] = 1

ans = 0
for i in range(1,n+1):
    for j in range(1,m+1):
        if board[i][j] == 0:
           ans += 1

print(ans)