#include <iostream>

using namespace std;

string s[101];
int n,m;
int dirY[8] = {-1,-1,-1,0,1,1,1,0};
int dirX[8] = {-1,0,1,1,1,0,-1,-1};
int find(int y,int x)
{
    int ret = 0;
    for(int i=0;i<8;++i)
    {
        if(y + dirY[i] * 2 >= 0 && x + dirX[i] * 2 >= 0 && y + dirY[i] * 2 < n && x + dirX[i] * 2 < m)
        {
            int nextY = y + dirY[i];
            int nextX = x + dirX[i];
            if(s[nextY][nextX] == 'O')
            {
                if(s[nextY + dirY[i]][nextX + dirX[i]] == 'X')
                {
                    ret++;
                }
            }
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        cin >> s[i];
    }
    int result = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(s[i][j] == 'F')
            {
                result += find(i,j);
            }
        }
    }
    cout << result;
}