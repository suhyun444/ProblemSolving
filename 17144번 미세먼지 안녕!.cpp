#include <iostream>

using namespace std;

int board[51][51];
int nextBoard[51][51];
int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };
int cleaner[2];
int r, c;
void DiffusionDust(int y, int x)
{
	int count = 0;
	int amount = board[y][x] / 5;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dirY[i];
		int nextX = x + dirX[i];
		if (0 <= nextX && nextX < c && 0 <= nextY && nextY < r)
		{
			if(board[nextY][nextX] != -1)
			{
				count++;
				nextBoard[nextY][nextX] += amount;
			}
		}
	}
	nextBoard[y][x] -= amount * count;
}
void DiffusionAllDust()
{
	for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)nextBoard[i][j] = board[i][j];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			DiffusionDust(i, j);
		}
	}

	for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)board[i][j] = nextBoard[i][j];
}
void RotateDust()
{
	//위에꺼 공기청정기
	//왼쪽 위에서 아래로
	for (int i = cleaner[0] - 1; i > 0; i--)
		board[i][0] = board[i - 1][0];
	//오른쪽 위에서 왼쪽 위로
	for (int i = 0; i < c - 1; i++)
		board[0][i] = board[0][i + 1];
	//오른쪽 아래에서 오른쪽 위로
	for (int i = 0; i < cleaner[0]; i++)
		board[i][c - 1] = board[i + 1][c - 1];
	//왼쪽 아래에서 오른쪽 아래로
	for (int i = c - 1; i > 0; i--)
		board[cleaner[0]][i] = board[cleaner[0]][i - 1];
	board[cleaner[0]][1] = 0;

	//아래꺼 공기청정기
	//왼쪽 아래에서 위로
	for (int i = cleaner[1] + 1; i < r - 1; i++)
		board[i][0] = board[i + 1][0];
	//오른쪽 아래에서 왼쪽 아래로
	for (int i = 0; i < c - 1; i++)
		board[r - 1][i] = board[r - 1][i + 1];
	//오른쪽 위에서 아래로
	for (int i = r - 1; i > cleaner[1]; i--)
		board[i][c - 1] = board[i - 1][c - 1];
	//왼쪽 위에서 오른쪽으로
	for (int i = c - 1; i > 0; i--)
		board[cleaner[1]][i] = board[cleaner[1]][i - 1];
	board[cleaner[1]][1] = 0;
}
int SumDust()
{
	int result = 0;
	for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)if (board[i][j] != -1)result += board[i][j];
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == -1)
			{
				if (cleaner[0] == 0)
					cleaner[0] = i;
				else
					cleaner[1] = i;
			}
		}
	}
	for (int i = 0; i < t; i++)
	{
		DiffusionAllDust();
		RotateDust();
	}
	cout << SumDust();
}