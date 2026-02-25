#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n;
int ans = 0;
int cache[1001][1001][3];
int board[1001][1001];
int dfs(int curY,int curX,int status)
{
    if(curY == n-1 && curX == n-1)
    {
        return 0;
    }
    int& ret = cache[curY][curX][status];
    if(ret != -1)return ret;
    ret = -1e9;
    if(curY + 1 < n)
    {
        if(board[curY + 1][curX] == status)
            ret = max(ret, dfs(curY + 1,curX,(status == 2)?0:status + 1) + 1);
        else 
            ret = max(ret,dfs(curY + 1,curX,status));
    }
    if(curX + 1 < n)
    {
        if(board[curY][curX + 1] == status)
            ret = max(ret,dfs(curY,curX + 1,(status == 2)?0:status + 1) + 1);
        else 
            ret = max(ret,dfs(curY,curX + 1,status));
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin >> n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin >> board[i][j];
        }
    }
    if(board[0][0] == 0)
        cout << dfs(0,0,1) + 1;
    else
        cout << dfs(0,0,0);
}
