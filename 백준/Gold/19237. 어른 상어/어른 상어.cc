#include <iostream>

using namespace std;

struct Shark {
	Shark() : y{ 0 }, x{ 0 }, curDirection{ 0 }, isAlive{ true } {}
public:
	int y, x;
	int curDirection;
	bool isAlive;
	int directions[4][4];
};
int n, m, k;
Shark sharks[401];
pair<int, int> board[21][21];
int dirY[4] = { -1,1,0,0 };
int dirX[4] = { 0,0,-1,1 };
void Smell()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j].second > 0)
			{
				board[i][j] = { board[i][j].first,board[i][j].second - 1 };
				if (board[i][j].second == 0)board[i][j] = { 0,0 };
			}
		}
	}
}
void Move()
{
	pair<int, int> nextBoard[21][21];
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)nextBoard[i][j] = board[i][j];
	for (int i = 1; i <= m; i++)
	{
		if (!sharks[i].isAlive)continue;
		int moveY = sharks[i].y;
		int moveX = sharks[i].x;
		//FindDirection
		for (int j = 0; j < 4; j++)
		{
			int nextDirection = sharks[i].directions[sharks[i].curDirection][j];
			int nextY = sharks[i].y + dirY[nextDirection];
			int nextX = sharks[i].x + dirX[nextDirection];
			if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
			{
				if (board[nextY][nextX].first == 0)
				{
					sharks[i].curDirection = nextDirection;
					moveY = nextY;
					moveX = nextX;
					break;
				}
			}
		}
		if (moveY == sharks[i].y && moveX == sharks[i].x)
		{
			for (int j = 0; j < 4; j++)
			{
				//현재 상어 냄새 위치 찾기
				int nextDirection = sharks[i].directions[sharks[i].curDirection][j];
				int nextY = sharks[i].y + dirY[nextDirection];
				int nextX = sharks[i].x + dirX[nextDirection];
				if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
				{
					if (board[nextY][nextX].first == i)
					{
						sharks[i].curDirection = nextDirection;
						moveY = nextY;
						moveX = nextX;
						break;
					}
				}
			}
		}

		sharks[i].y = moveY;
		sharks[i].x = moveX;
		if (nextBoard[moveY][moveX].first == 0 || nextBoard[moveY][moveX].first == i)
		{
			nextBoard[moveY][moveX] = { i,k + 1};
		}
		else if(nextBoard[moveY][moveX].first != 0 && nextBoard[moveY][moveX].first < i)
		{
			sharks[i].isAlive = false;
		}
	}
	
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)board[i][j] = { nextBoard[i][j].first,nextBoard[i][j].second};
}
bool isEnd()
{
	for (int i = 2; i <= m; i++)
	{
		if (sharks[i].isAlive)return false;
	}
	return true;
}
void PrintBoard()
{
	cout << "Print Start\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j].first << " , " << board[i][j].second << " | ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n;j++)
		{
			int a;
			cin >> a;
			if (a != 0)board[i][j] = { a,k };
			else board[i][j] = { 0,0 };
			sharks[a].y = i;
			sharks[a].x = j;
		}
	}
	for (int i = 1; i <= m; i++) 
	{
		int dir;
		cin >> dir;
		sharks[i].curDirection = dir - 1;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int dir;
				cin >> dir;
				sharks[i].directions[j][k] = dir - 1;
			}
		}
	}
	int result = 0;
	while (true)
	{
		//PrintBoard();
		if (result > 1000)
		{
			cout << "-1";
			return 0;
		}
		if (isEnd())break;
		Move();
		Smell();
		result++;
	}
	cout << result;
}