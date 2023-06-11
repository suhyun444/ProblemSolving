dirY = [0,1,0,-1]
dirX = [1,0,-1,0]

n,m = map(int,input().split(' '))
result = []
board = []
visited = [[False for j in range(m)] for i in range(n)]
for i in range(n):
    board.append(input())

for i in range(n):
    for j in range(m):
        if board[i][j] == '*':
            size = 1
            canMake = True
            while True:
                for k in range(4):
                       nextY = i + dirY[k] * size
                       nextX = j + dirX[k] * size
                       if nextX < 0 or nextX >= m or nextY < 0 or nextY >= n or board[nextY][nextX] == '.':
                           canMake = False
                           break
                if canMake:
                    visited[i][j] = True
                    for k in range(4):
                        nextY = i + dirY[k] * size
                        nextX = j + dirX[k] * size
                        visited[nextY][nextX] = True
                    size += 1
                else:
                    if size != 1:
                        result.append(str(i + 1) + ' '+str(j + 1) +' ' +str(size - 1))
                    break

for i in range(n):
    for j in range(m):
        if board[i][j] == '*' and visited[i][j] == False:
            print("-1")
            exit(0)

print(len(result))
for ans in result:
    print(ans)