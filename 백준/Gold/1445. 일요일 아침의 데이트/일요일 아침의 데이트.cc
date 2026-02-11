#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n,m;
int adj[51][51][51][51];
int dist[51][51];
char board[51][51];
int dirY[4] = {0,1,0,-1};
int dirX[4] = {1,0,-1,0};
bool visited[51][51];
bool isNearTrash(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dirY[i];
        int nx = x + dirX[i];
        
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (board[ny][nx] == 'g') return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int startY,startX,endY,endX;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin >> board[i][j];
            if(board[i][j] == 'S')
            {
                startY = i;
                startX = j;
            }
            else if(board[i][j] == 'F')
            {
                endY = i;
                endX = j;
            }
            dist[i][j] = 1e9;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            for(int k=0;k<4;++k)
            {
                int nextY = i + dirY[k];
                int nextX = j + dirX[k];
                if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
                {
                    if(board[nextY][nextX] == 'F' || board[nextY][nextX] == 'S')adj[i][j][nextY][nextX] = 0;
                    else if(board[nextY][nextX] == 'g')adj[i][j][nextY][nextX] = 10000;
                    else if(isNearTrash(nextY,nextX))adj[i][j][nextY][nextX] = 1;
                    else adj[i][j][nextY][nextX] = 0;
                }
            }
        }
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{startY,startX}});
    dist[startY][startX] = 0;
    while(!pq.empty())
    {
        pair<int,pair<int,int>> cur = pq.top();
        pq.pop();
        if(dist[cur.second.first][cur.second.second] < cur.first)continue;
        for(int i=0;i<4;++i)
        {
            int nextY = cur.second.first + dirY[i];
            int nextX = cur.second.second + dirX[i];
            if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
            {
                int curCost = cur.first;
                int cost = adj[cur.second.first][cur.second.second][nextY][nextX];
                if(dist[nextY][nextX] > curCost + cost)
                {
                    dist[nextY][nextX] = curCost + cost;
                    pq.push({dist[nextY][nextX],{nextY,nextX}});
                }
            }
        }
    }

    cout << dist[endY][endX] / 10000 << " " << dist[endY][endX] % 10000;
}
