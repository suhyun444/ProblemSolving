#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;


int n;
vector<pair<int,int>> students;
char board[6][6];
int dirY[4] = {0,1,0,-1};
int dirX[4] = {1,0,-1,0};
bool check()
{
    for(int i=0;i<students.size();++i)
    {
        for(int j=0;j<4;++j)
        {
            int range = 1;
            while(true)
            {
                int nextY = students[i].first + dirY[j] * range;
                int nextX = students[i].second + dirX[j] * range;
                if(0 > nextY || nextY >= n || 0 > nextX || nextX >= n)break;
                else if(board[nextY][nextX] == 'O')break;
                else if(board[nextY][nextX] == 'T')
                {
                    return false;
                }
                range++;
            }
        }
    }
    return true;
}
bool back(int cur,int size)
{
    if(cur == (n*n)) return false;
    if(size == 3)
    {
        return check();
    }
    if(back(cur + 1,size))
        return true;
    
    if(board[cur/n][cur%n] == 'X')
    {
        board[cur/n][cur%n] = 'O';
        if(back(cur + 1,size + 1))
            return true;
        board[cur/n][cur%n] = 'X';
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin >> board[i][j];
            if(board[i][j] == 'S')
            {
                students.push_back({i,j});
            }
        }
    }
    cout << (back(0,0)?"YES":"NO");
}
