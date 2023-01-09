#include <iostream>

using namespace std;

/*  1
* 3 0 2
*   4
*   5
*/

int dice[6];
void RollLeft()
{
	swap(dice[0], dice[3]);
	swap(dice[0], dice[5]);
	swap(dice[0], dice[2]);
}
void RollRight()
{
	swap(dice[0], dice[2]);
	swap(dice[0], dice[5]);
	swap(dice[0], dice[3]);
}
void RollUp()
{
	swap(dice[0], dice[1]);
	swap(dice[0], dice[5]);
	swap(dice[0], dice[4]);
}
void RollDown()
{
	swap(dice[0], dice[4]);
	swap(dice[0], dice[5]);
	swap(dice[0], dice[1]);
}
int GetUpFace()
{
	return dice[5];
}
pair<int,int> GetDirection(int type)
{
	//y,x
	if (type == 1)
		return { 0,1 };
	if (type == 2)
		return { 0,-1 };
	if (type == 3)
		return { -1,0 };
	if (type == 4)
		return { 1,0 };
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int board[21][21];
	int n, m, x, y, k;
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		int type;
		cin >> type;
		pair<int, int> direction = GetDirection(type);
		int nextY = y + direction.first;
		int nextX = x + direction.second;
		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)continue;
		x = nextX;
		y = nextY;
		if (type == 1)
			RollRight();
		else if (type == 2)
			RollLeft();
		else if (type == 3)
			RollUp();
		else if (type == 4)
			RollDown();
		if (board[y][x] == 0)
		{
			board[y][x] = dice[0];
		}
		else
		{
			dice[0] = board[y][x];
			board[y][x] = 0;
		}
		cout << dice[5] << "\n";
	}
}