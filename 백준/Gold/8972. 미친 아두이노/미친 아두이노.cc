#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;


int n,m;
int dirY[10] = {0,1,1,1,0,0,0,-1,-1,-1};
int dirX[10] = {0,-1,0,1,-1,0,1,-1,0,1};
bool visited[101][101];
vector<pair<int,int>> deleteQueue;
pair<int,int> player;
class Arduino;
vector<Arduino*> arduinos;
class Arduino
{
    public:
    Arduino(int x,int y) : x{x},y{y}{}
    bool disabled = false;
    int x,y;
    bool move(pair<int,int> player)
    {
        if(disabled) return false;
        int arduinoDirX = max(min(1,player.first - x),-1);
        int arduinoDirY = max(min(1,player.second - y),-1);
        x += arduinoDirX;
        y += arduinoDirY;
        if(visited[x][y])deleteQueue.push_back({x,y});
        visited[x][y] = true;
        if(x == player.first && y == player.second)
            return true;
        return false;
    }
};
bool Move(int dir)
{
    player.first += dirX[dir];
    player.second += dirY[dir];
    for(int j=0;j<arduinos.size();++j)
    {
        if(arduinos[j]->disabled)continue;
        if (arduinos[j]->x == player.first && arduinos[j]->y == player.second)
        {
            return true;
        }
    }
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)visited[j][i] = false;
    for(int i=0;i<arduinos.size();++i)
    {
        if(arduinos[i]->move(player))
            return true;
    }
    for(int i=0;i<deleteQueue.size();++i)
    {
        for(int j=0;j<arduinos.size();++j)
        {
            if(arduinos[j]->x == deleteQueue[i].first && arduinos[j]->y == deleteQueue[i].second)
            {
                arduinos[j]->disabled = true;
            }
        }
    }
    deleteQueue.clear();
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            char c;
            cin >> c;
            if(c == 'I')player = {j,i};
            else if(c == 'R')
            {
                arduinos.push_back(new Arduino(j,i));
            }
        }
    }
    string s;
    cin >> s;
    for(int i=0;i<s.length();++i)
    {
        bool result = Move(s[i] - '0');
        if(result)
        {
            cout << "kraj "<<i + 1 << "\n";
            return 0;
        }
    }
    char board[101][101];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            board[i][j] = '.';
    board[player.second][player.first] = 'I';
    for (int i = 0; i < arduinos.size(); ++i)
    {
        if (!arduinos[i]->disabled)
            board[arduinos[i]->y][arduinos[i]->x] = 'R';
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}
