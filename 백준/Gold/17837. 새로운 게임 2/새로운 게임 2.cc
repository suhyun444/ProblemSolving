#include <iostream>
#include <vector>

using namespace std;

struct Chess {
    Chess() : x{ 0 }, y{ 0 }, dir{ 0 } {}
    Chess(int x, int y, int dir) : x{ x }, y{ y }, dir{ dir } {}
    int x, y, dir;
};
Chess chess[10];
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,-1,0,1 };
vector<int> chessBoard[12][12];
int board[12][12];
int n, k;
bool Solve()
{
    for (int i = 0; i < k; i++)
    {
        Chess cur = chess[i];
        vector<int> moveChess;
        for (int j = 0; j < chessBoard[cur.y][cur.x].size(); j++)
        {
            if (chessBoard[cur.y][cur.x][j] == i)
            {
                int size = chessBoard[cur.y][cur.x].size() - j;
                for (int l = 0; l < size; l++)
                {
                    moveChess.push_back(chessBoard[cur.y][cur.x][j + l]);
                }
                for (int l = 0; l < size; l++)
                {
                    chessBoard[cur.y][cur.x].pop_back();
                }
                break;
            }
        }
        int nextY = cur.y + dirY[cur.dir];
        int nextX = cur.x + dirX[cur.dir];
        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || board[nextY][nextX] == 2)
        {
            int nextDir = (cur.dir + 2) % 4;
            chess[i].dir = nextDir;
            nextY = cur.y + dirY[nextDir];
            nextX = cur.x + dirX[nextDir];
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || board[nextY][nextX] == 2)
            {
                for (int j = 0; j < moveChess.size(); j++)
                {
                    chessBoard[cur.y][cur.x].push_back(moveChess[j]);
                }
            }
            else
            {
                if (board[nextY][nextX] == 0)
                {
                    for (int j = 0; j < moveChess.size(); j++)
                    {
                        int curIndex = moveChess[j];
                        chess[curIndex].y = nextY;
                        chess[curIndex].x = nextX;
                        chessBoard[nextY][nextX].push_back(curIndex);
                    }
                }
                else if (board[nextY][nextX] == 1)
                {
                    for (int j = moveChess.size() - 1; j >= 0; j--)
                    {
                        int curIndex = moveChess[j];
                        chess[curIndex].y = nextY;
                        chess[curIndex].x = nextX;
                        chessBoard[nextY][nextX].push_back(curIndex);
                    }
                }
            }
        }
        else if (board[nextY][nextX] == 0)
        {
            for (int j = 0; j < moveChess.size(); j++)
            {
                int curIndex = moveChess[j];
                chess[curIndex].y = nextY;
                chess[curIndex].x = nextX;
                chessBoard[nextY][nextX].push_back(curIndex);
            }
        }
        else if (board[nextY][nextX] == 1)
        {
            for (int j = moveChess.size() - 1; j >= 0; j--)
            {
                int curIndex = moveChess[j];
                chess[curIndex].y = nextY;
                chess[curIndex].x = nextX;
                chessBoard[nextY][nextX].push_back(curIndex);
            }
        }

        if (chessBoard[chess[i].y][chess[i].x].size() >= 4)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int y, x, dir;
        cin >> y >> x >> dir;
        dir--;
        if (dir == 2) dir = 1;
        else if (dir == 1)dir = 2;
        chess[i] = Chess(x - 1, y - 1, dir);
        chessBoard[y - 1][x - 1].push_back(i);
    }
    for (int i = 1; i < 1001; i++)
    {
        if (Solve())
        {
            cout << i;
            return 0;
        }
    }
    cout << "-1";
}