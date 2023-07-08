#include <iostream>
#include <iomanip>

using namespace std;

int board[50][50];
int dirY[4] = { 0,-1,0,1 };
int dirX[4] = { 1,0,-1,0 };
int main()
{
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int y = 0, x = 0;
	int count = 1;
	if (r1 <= 0 && 0 <= r2 && c1 <= 0 && 0 <= c2)board[y - r1][x - c1] = 1;
	int upCount = 0;
	int dist = 1;
	int direction = 0;
	while (count < 10001 * 10001)
	{
		for (int i = 0; i < dist; i++)
		{
			y += dirY[direction];
			x += dirX[direction];
			count++;
			if (r1 <= y && y <= r2 && c1 <= x && x <= c2)
			{
				board[y - r1][x - c1] = count;
			}
		}
		upCount++;
		if (upCount == 2)
		{
			upCount = 0;
			dist++;
		}
		direction = (direction + 1) % 4;
	}
	int maxNum = 0;
	for (int i = 0; i <= r2 - r1; i++)
	{
		for (int j = 0; j <= c2 - c1; j++)
		{
			maxNum = max(maxNum, board[i][j]);
		}
	}
	int digit = 0;
	while (maxNum > 0)
	{
		digit++;
		maxNum /= 10;
	}
	for (int i = 0; i <= r2 -r1; i++)
	{
		for (int j = 0; j <= c2 -c1; j++)
		{
			cout << setw(digit) << board[i][j] << " ";
		}
		cout << "\n";
	}

}