#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int n, m;
int board[21][21];
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
bool visited[21][21];
int curUseRainbowCount;
void ResetVisitedRainbowBlocks()	
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0)visited[i][j] = false;
		}
	}
}
int Dfs(int y, int x,int color)
{
	if (board[y][x] == 0)curUseRainbowCount++;
	int num = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dirY[i];
		int nextX = x + dirX[i];
		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !visited[nextY][nextX])
		{
			if (board[nextY][nextX] == 0 || board[nextY][nextX] == color)
			{
				visited[nextY][nextX] = true;
				num += Dfs(nextY, nextX, color);
			}
		}
	}
	return num;
}
void SetMaxInfo(int& maxNum, int& useRainbowCount, int& y, int& x,int cur,int i,int j)
{
	maxNum = cur;
	useRainbowCount = curUseRainbowCount;
	y = i; x = j;
}
void EraseDfs(int y, int x, int color)
{
	board[y][x] = -2;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dirY[i];
		int nextX = x + dirX[i];
		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !visited[nextY][nextX])
		{
			if (board[nextY][nextX] == 0 || board[nextY][nextX] == color)
			{
				visited[nextY][nextX] = true;
				EraseDfs(nextY, nextX, color);
			}
		}
	}
}
int DfsAll()
{
	int maxNum = 0;
	int useRainbowCount = 0;
	int y = 0, x = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && board[i][j] > 0)
			{
				ResetVisitedRainbowBlocks();
				curUseRainbowCount = 0;
				visited[i][j] = true;
				int cur = Dfs(i, j, board[i][j]);
				if (maxNum < cur)
					SetMaxInfo(maxNum, useRainbowCount, y, x, cur, i, j);
				else if (maxNum == cur)
				{
					if (useRainbowCount < curUseRainbowCount)
						SetMaxInfo(maxNum, useRainbowCount, y, x, cur, i, j);
					else if (useRainbowCount == curUseRainbowCount)
					{
						if (y < i)
							SetMaxInfo(maxNum, useRainbowCount, y, x, cur, i, j);
						else if(y == i && x < j)
							SetMaxInfo(maxNum, useRainbowCount, y, x, cur, i, j);
					}
				}
			}
		}
	}
	memset(visited, false, sizeof(visited));
	EraseDfs(y, x, board[y][x]);
	return maxNum;
}
void RotateBoard()
{
	int copyBoard[21][21];
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)copyBoard[i][j] = board[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[n - 1 - j][i] = copyBoard[i][j];
		}
	}
}
void Gravity()
{
	for (int x = 0; x < n; x++)
	{
		int curY = n - 1;
		for (int y = n - 1; y >= 0; y--)
		{
			if (board[y][x] == -1)curY = y - 1;
			else if (board[y][x] >= 0)
			{
				int block = board[y][x];
				board[y][x] = -2;
				board[curY][x] = block;
				curY--;
			}
		}
	}
}
void PrintBoard()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == -2)cout << "\t";
			else cout << board[i][j] << "\t";
		}
		cout << "\n";
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int result = 0;
	while (true)
	{
		int point = DfsAll();
		if (point <= 1)break;
		result += pow(point, 2);
		Gravity();
		RotateBoard();
		Gravity();
	}
	cout << result;
}