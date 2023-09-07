#include <iostream>
#include <queue>
using namespace std;

int n, m;
char board[11][11];
bool visited[11][11][11][11];
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
pair<int, int> Roll(int startY, int startX, int direction)
{
    while (true)
    {
        startY += dirY[direction];
        startX += dirX[direction];
        if (board[startY][startX] == '#')
        {
            startY -= dirY[direction];
            startX -= dirX[direction];
            board[startY][startX] = '#';
            return { startY,startX };
        }
        else if (board[startY][startX] == 'O')return { -1,-1 };
    }
}
pair<pair<int,int>,pair<int,int>> StartRoll(pair<pair<int, int>, pair<int, int>> cur, int direction)
{
    pair<int, int> nextRed;
    pair<int, int> nextBlue;
    if (direction == 0)
    {
        if (cur.first.second > cur.second.second)
        {
            nextRed = Roll(cur.first.first, cur.first.second, direction);
            nextBlue = Roll(cur.second.first, cur.second.second, direction);
        }
        else
        {
            nextBlue = Roll(cur.second.first, cur.second.second, direction);
            nextRed = Roll(cur.first.first, cur.first.second, direction);
        }
    }
    else if (direction == 1)
    {
        if (cur.first.first > cur.second.first)
        {
            nextRed = Roll(cur.first.first, cur.first.second, direction);
            nextBlue = Roll(cur.second.first, cur.second.second, direction);
        }
        else
        {
            nextBlue = Roll(cur.second.first, cur.second.second, direction);
            nextRed = Roll(cur.first.first, cur.first.second, direction);
        }
    }
    else if (direction == 2)
    {
        if (cur.first.second < cur.second.second)
        {
            nextRed = Roll(cur.first.first, cur.first.second, direction);
            nextBlue = Roll(cur.second.first, cur.second.second, direction);
        }
        else
        {
            nextBlue = Roll(cur.second.first, cur.second.second, direction);
            nextRed = Roll(cur.first.first, cur.first.second, direction);
        }
    }
    else if (direction == 3)
    {
        if (cur.first.first < cur.second.first)
        {
            nextRed = Roll(cur.first.first, cur.first.second, direction);
            nextBlue = Roll(cur.second.first, cur.second.second, direction);
        }
        else
        {
            nextBlue = Roll(cur.second.first, cur.second.second, direction);
            nextRed = Roll(cur.first.first, cur.first.second, direction);
        }
    }
    return { nextRed,nextBlue };
}
int Bfs(pair<int, int> redStart, pair<int, int> blueStart)
{
    visited[redStart.first][redStart.second][blueStart.first][blueStart.second];
    queue <pair<pair<int, int>, pair<int, int>>> q;
    q.push({ redStart,blueStart });
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            pair<pair<int, int>, pair<int, int>> cur = q.front();
            q.pop();
            for (int j = 0; j < 4; ++j)
            {
                pair<pair<int, int>, pair<int, int>> next = StartRoll(cur, j);
                pair<int, int> nextRed = next.first;
                pair<int, int> nextBlue = next.second;
                if (nextRed.first == -1 && nextBlue.first == -1)continue;
                if (nextRed.first == -1)return level + 1;
                if (nextBlue.first == -1)
                {
                    board[nextRed.first][nextRed.second] = '.';
                    continue;
                }
                board[nextRed.first][nextRed.second] = '.';
                board[nextBlue.first][nextBlue.second] = '.';
                if (!visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second])
                {   
                    q.push({ nextRed,nextBlue });
                    visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second] = true;
                }
            }
        }
        if (++level == 10)
            return -1;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int redY, redX, blueY, blueX;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                redY = i;
                redX = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                blueY = i;
                blueX = j;
                board[i][j] = '.';
            }
        }
    }
    cout << Bfs({ redY,redX }, { blueY,blueX });
}