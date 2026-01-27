#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n,m,t,d;
int board[25][25];
int dist[625][625];
int dirY[4] = {-1,0,1,0};
int dirX[4] = {0,1,0,-1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t >> d;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            char c;
            cin >> c;
            if('A' <= c && c <= 'Z')
                board[i][j] = c-'A';
            else
                board[i][j] = c - 'a' + 26;
        }
    }
    for(int i=0;i<625;++i)for(int j=0;j<625;++j)dist[i][j] = 1e9;
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
                    int diff = abs(board[i][j] - board[nextY][nextX]);
                    if(diff <= t)
                    {
                        if(board[nextY][nextX] > board[i][j])
                            dist[i*m+j][nextY*m+nextX] = pow(diff,2); 
                        else
                            dist[i*m+j][nextY*m+nextX] = 1; 
                    }
                }
            }
        }
    }
    int size = n*m;
    for(int k=0;k<size;++k)
    {
        for(int i=0;i<size;++i)
        {
            for(int j=0;j<size;++j)
            {
                if(i == j)dist[i][j] = 0;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int result = 0;
    for(int i=0;i<size;++i)
    {
        if(dist[0][i] + dist[i][0] <= d)
        {
            result = max(result,board[i/m][i%m]);
        }
    }
    cout << result;
}