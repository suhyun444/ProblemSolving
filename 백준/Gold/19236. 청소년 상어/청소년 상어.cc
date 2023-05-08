#include <iostream>
#include <vector>

using namespace std;

struct Fish {
    Fish() 
    {
        direction = 0;
        x = 0;
        y = 0;
        alive = true;
    }
    Fish(int direction, int y, int x) : direction{ direction }, y{ y }, x{ x }, alive{ true } {}
    int direction;
    int x, y;
    bool alive;
};
//direction 저장
Fish fish[17];
//cost저장
int board[4][4];
//direction
//위가 1 반시계방향으로 진행
int dirX[9] = {0, 0,-1,-1,-1,0,1,1,1 };
int dirY[9] = {0, -1,-1,0,1,1,1,0,-1 };
int ans = 0;

void CopyBoard(int copied[][4],Fish copiedFish[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            copied[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < 17; i++)copiedFish[i] = fish[i];
}
void PasteBoard(int copied[][4],Fish copiedFish[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = copied[i][j];
        }
    }
    for (int i = 0; i < 17; i++)fish[i] = copiedFish[i];
}
void MoveFishs(int sharkY,int sharkX)
{
    for (int i = 1; i <= 16; i++)
    {
        if (!fish[i].alive)continue;
        bool isMoved = false;
        while (!isMoved)
        {
            Fish f = fish[i];
            int nextX = dirX[f.direction] + f.x;
            int nextY = dirY[f.direction] + f.y;
            //cout << i << " : " << f.direction << "\n";
            //cout << "cur pos : " << f.y << " , " << f.x << " to " << nextY << " , " <<  nextX <<  "\n";

            if (nextX < 0 || nextX >= 4 || nextY < 0 || nextY >= 4 || (nextX == sharkX && nextY == sharkY))
            {
                fish[i].direction++;
                if (fish[i].direction == 9)fish[i].direction = 1;
                continue;
            }
            int temp = board[nextY][nextX];
            board[nextY][nextX] = board[f.y][f.x];
            board[f.y][f.x] = temp;
            fish[temp].y = f.y; fish[temp].x = f.x;
            fish[i].y = nextY; fish[i].x = nextX;
            isMoved = true;
        }
    }
}
void Solve(int y,int x,int dir,int sum)
{
    ans = max(ans, sum);
    int copyBoard[4][4];
    Fish copyFish[17];
    CopyBoard(copyBoard,copyFish);
    MoveFishs(y,x);
    for (int i = 1; i < 4; i++)
    {
        int nextY = y + dirY[dir] * i;
        int nextX = x + dirX[dir] * i;
        if (nextX < 0 || nextX >= 4 || nextY < 0 || nextY >= 4)break;
        if (fish[board[nextY][nextX]].alive)
        {
            int point = board[nextY][nextX];
            fish[point].alive = false;
            Solve(nextY,nextX,fish[point].direction,sum + point);
            fish[point].alive = true;
        }
    }
    PasteBoard(copyBoard,copyFish);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a, b;
            cin >> a >> b;
            board[i][j] = a;
            fish[a] = Fish(b, i, j);
        }
    }
    int result = 0;
    result = board[0][0];
    fish[result].alive = false;
    Solve(0, 0, fish[result].direction, result);
    cout << ans;
}