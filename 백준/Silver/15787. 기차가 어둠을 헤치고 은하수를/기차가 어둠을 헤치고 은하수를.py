n,m = map(int,input().split(' '))
result = [0 for i in range(n + 1)]
for _ in range(m):
    orderList = list(map(int,input().split(' ')))
    order = orderList[0]
    i = orderList[1]
    if order == 1:
        x = orderList[2]
        result[i] |= (1 << (x-1))
    if order == 2:
        x = orderList[2]
        result[i] = ~result[i]
        result[i] |= (1 << (x-1))
        result[i] = ~result[i]
    if order == 3:
        result[i] <<= 1
        result[i] &= 0xfffff
    if order == 4:
        result[i] >>= 1
ans = 0
visited = [False for i in range(2**21)]
for i in range(1, n+1):
    if visited[result[i]]:
        continue
    visited[result[i]] = True
    ans += 1
print(ans)