#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int n,m;
queue<pair<int,int>> sands;
char board[1001][1001];
char copy_board[1001][1001];
bool canDelete(int y,int x)
{
    int waterCount = 0;
    for(int dirX = -1;dirX<=1;++dirX)
    {
        for(int dirY = -1;dirY <= 1;++dirY)
        {
            if(dirY == dirX && dirX == 0)continue;
            int nextY = y + dirY;
            int nextX = x + dirX;
            if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
                if(copy_board[nextY][nextX] == 'a') 
                    waterCount++;
        }
    }
    if(waterCount >= (board[y][x] - '0'))
        return true;
    return false;
}
void waves()
{
    int size = sands.size();
    for(int i=0;i<size;++i)
    {
        pair<int,int> cur = sands.front();
        sands.pop();
        for(int dirX = -1;dirX <= 1;++dirX)
        {
            for(int dirY = -1;dirY <= 1;++dirY)
            {
                if(dirY == dirX && dirX == 0)continue;
                int nextY = cur.first + dirY;
                int nextX = cur.second + dirX;
                if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
                    if(board[nextY][nextX] != 'a') 
                    {
                        board[nextY][nextX] -= 1;
                        if(board[nextY][nextX] <= '0')
                        {
                            board[nextY][nextX] = 'a';
                            sands.push({nextY,nextX});
                        }
                    }
            }
        }
    }


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
            cin >> board[i][j];
            if(board[i][j] == '.')board[i][j] = 'a';
            copy_board[i][j] = board[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(board[i][j] == 'a')
            {
                for(int dirX = -1;dirX <= 1;++dirX)
                {
                    for(int dirY = -1;dirY <= 1;++dirY)
                    {
                        if(dirY == dirX && dirX == 0)continue;
                        int nextY = i + dirY;
                        int nextX = j + dirX;
                        if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
                            if(copy_board[nextY][nextX] != 'a')
                            {
                                copy_board[nextY][nextX] -= 1;
                                if(copy_board[nextY][nextX] <= '0')
                                {
                                    copy_board[nextY][nextX] = 'a';
                                    sands.push({nextY,nextX});
                                }
                            }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) board[i][j] = copy_board[i][j];
    int count = 0;
    while(!sands.empty())
    {
        waves();
        count++;
    }
    cout << count;
}