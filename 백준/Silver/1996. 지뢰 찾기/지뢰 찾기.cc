#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int dirY[8] = {-1,-1,-1,0,1,1,1,0};
int dirX[8] = {-1,0,1,1,1,0,-1,-1};
int main() {
    int n;
    cin >> n;
    char board[1001][1001];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }
    int result[1001][1001];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == '.')
            {
                int cur = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int nextY = i + dirY[k];
                    int nextX = j + dirX[k];
                    if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)continue;
                    if (board[nextY][nextX] != '.')
                    {
                        cur += board[nextY][nextX] - '0';
                    }
                }
                result[i][j] = cur;
            }
            else {
                result[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (result[i][j] == -1)
                cout << "*";
            else if (result[i][j] >= 10)
                cout << "M";
            else
                cout << result[i][j];
        }
        cout << "\n";
    }
}