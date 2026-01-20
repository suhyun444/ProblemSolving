#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, m, g, r;
int dirY[4] = {0,-1,0,1};
int dirX[4] = {1,0,-1,0};
int board[51][51];
int copyBoard[51][51];
bool visited[51][51];
vector<pair<int,int>> plantGround;
vector<pair<int,int>> back;
int ans = 0;
int bfs()
{
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)board[i][j] = copyBoard[i][j];
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int,int>,pair<pair<int,int>,int>>> q;
    for(int i=0;i<back.size();++i)
    {
        q.push({plantGround[back[i].first],{plantGround[back[i].first],back[i].second}});
    }
    int result = 0;
    int level = 0;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            pair<pair<int,int>,pair<pair<int,int>,int>> cur= q.front();
            q.pop();
            if(board[cur.second.first.first][cur.second.first.second] == 1e9)continue;
            int curColor = level + ((cur.second.second == 0) ? 500 : 6000);
            if(level > 0 && board[cur.first.first][cur.first.second] + curColor == 6500 + level + level)
            {
                result += 1;
                board[cur.first.first][cur.first.second] = 1e9;
                visited[cur.first.first][cur.first.second] = true;
                continue;
            }
            if(board[cur.first.first][cur.first.second] == 1e9) continue;
            if(visited[cur.first.first][cur.first.second]) continue;
            board[cur.first.first][cur.first.second] = curColor;
            visited[cur.first.first][cur.first.second] = true;

            for(int i=0;i<4;++i)
            {
                int nextY = cur.first.first + dirY[i];
                int nextX = cur.first.second + dirX[i];
                if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
                {
                    if(board[nextY][nextX] == 1 && !visited[nextY][nextX])
                    {
                        q.push({{nextY,nextX},{{cur.first.first,cur.first.second},cur.second.second}});
                    }
                }
            }
        }
        level++;
    }
    return result;
}
void backtracking(int index,int rCount,int gCount)
{
    if(rCount == 0 && gCount == 0)
    {
        ans = max(ans,bfs());
        return;
    }
    if(index == plantGround.size())return;
    if(plantGround.size() - index - 1 >= rCount + gCount)
    {
        backtracking(index + 1,rCount,gCount);
    }
    if(rCount > 0)
    {
        back.push_back({index,0});
        backtracking(index + 1,rCount -1,gCount);
        back.pop_back();
    }
    if(gCount > 0)
    {
        back.push_back({index,1});
        backtracking(index + 1,rCount,gCount - 1);
        back.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> g >> r;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin >> board[i][j];
            copyBoard[i][j] = board[i][j];
            if(board[i][j] == 2)
            {
                plantGround.push_back({i,j});
                board[i][j] = 1;
                copyBoard[i][j] = 1;
            }
        }
    }
    backtracking(0,r,g);
    cout << ans;
}