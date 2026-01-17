#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

//8시 35분 시작
//bfs + 2차원 visited
//처음 나오는 #을 +로 바꾼다음 시작위치로 지정
//이후 4방향중에 이동 가능한 위치 + 방향 q에 넣은상태로 q.push
//q에는 3가지 정보가 있다 방향, 위치, 방향 바꾼 횟수

int n;
char board[51][51];
int visited[4][51][51];
int dirY[4] = {-1,0,1,0};
int dirX[4] = {0,1,0,-1};
int bfs(int startY,int startX)
{
    //{방향 바꾼 횟수, 방향},{y,x}
    priority_queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{startY,startX}});
    q.push({{0,1},{startY,startX}});
    q.push({{0,2},{startY,startX}});
    q.push({{0,3},{startY,startX}});
    visited[0][startY][startX] = 0;
    visited[1][startY][startX] = 0;
    visited[2][startY][startX] = 0;
    visited[3][startY][startX] = 0;
    int result = 2e9;
    while(!q.empty())
    {
        pair<pair<int,int>,pair<int,int>> cur = q.top();
        q.pop();
        int nextY = cur.second.first + dirY[cur.first.second];
        int nextX = cur.second.second + dirX[cur.first.second];
        if(0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
            {
                if(cur.first.first > visited[cur.first.second][nextY][nextX] || board[nextY][nextX] == '*')
                    continue;
                if(board[nextY][nextX] == '.')
                {
                    q.push({cur.first,{nextY,nextX}});
                    visited[cur.first.second][nextY][nextX] = cur.first.first;
                }
                else if(board[nextY][nextX] == '!')
                {
                    int dir1 = (cur.first.second - 1 < 0) ? 3 : cur.first.second - 1;
                    int dir2 = (cur.first.second + 1) % 4;
                    q.push({{cur.first.first - 1,dir1},{nextY,nextX}});
                    visited[dir1][nextY][nextX] = cur.first.first + 1;
                    q.push({{cur.first.first - 1,dir2},{nextY,nextX}});
                    visited[dir2][nextY][nextX] = cur.first.first + 1;
                    q.push({cur.first,{nextY,nextX}});
                    visited[cur.first.second][nextY][nextX] = cur.first.first;
                }
                else if(board[nextY][nextX] == '#')
                {
                    return -cur.first.first;
                }
            }
        
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int startY = -1,startX;
    for(int i=0;i<4;++i)for(int j=0;j<n;++j)for(int k=0;k<n;++k)visited[i][j][k] = 2e9;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin >> board[i][j];
            if(board[i][j] == '#' && startY == -1)
            {
                board[i][j] = '+';
                startY = i;
                startX = j;
            }
        }
    }
    cout << bfs(startY,startX);
}