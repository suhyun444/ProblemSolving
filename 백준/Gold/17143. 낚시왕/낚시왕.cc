#include <iostream>
#include <cstring>
using namespace std;
struct Shark {
	int y, x, s, d, z;
	bool alive;
	Shark() :y{ 0 }, x{ 0 }, s{ 0 }, d{ 0 }, z{ 0 }, alive{ true } {};
	Shark(int y, int x, int s, int d, int z) : y{ y }, x{ x }, s{ s }, d{ d }, z{ z }, alive{ true } {};

};
int r, c, m;
Shark shark[10001];
int board[101][101];
int dirY[4] = { -1,1,0,0 };
int dirX[4] = { 0,0,1,-1 };
void PrintBoard()
{
	cout << "printStart\n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << shark[board[i][j]].z << "," << shark[board[i][j]].d << " | ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void MoveShark()
{
	memset(board, 0, sizeof(board));
	for (int i = 1; i <= m; i++)
	{
		if (shark[i].alive == false)continue;
		int dir = shark[i].d;
		if (dir == 1)
		{
			if (shark[i].y - shark[i].s >= 0)shark[i].y -= shark[i].s;
			else
			{
				int remain = shark[i].s - shark[i].y;
				int result = remain / (r - 1);
				remain %= (r - 1);
				if (result % 2 == 1)
				{
					if (remain == 0)shark[i].d = 2;
					shark[i].y = r - remain - 1;
				}
				else
				{
					shark[i].y = remain;
					shark[i].d = 2;
				}
			}
		}
		if (dir == 2)
		{
			if (shark[i].y + shark[i].s < r)shark[i].y += shark[i].s;
			else
			{
				int remain = shark[i].s - (r - shark[i].y - 1);
				int result = remain / (r - 1);
				remain %= (r - 1);
				if (result % 2 == 1)
				{
					if (remain == 0)shark[i].d = 1;
					shark[i].y = remain;
				}
				else
				{
					shark[i].y = r - remain - 1;
					shark[i].d = 1;
				}
			}
		}
		if (dir == 3)
		{
			if (shark[i].x + shark[i].s < c)shark[i].x += shark[i].s;
			else
			{
				int remain = shark[i].s - (c - shark[i].x - 1);
				int result = remain / (c - 1);
				remain %= (c - 1);
				if (result % 2 == 1)
				{
					if (remain == 0)shark[i].d = 4;
					shark[i].x = remain;
				}
				else
				{
					shark[i].x = c - remain - 1;
					shark[i].d = 4;
				}
			}
		}
		if (dir == 4)
		{
			if (shark[i].x - shark[i].s >= 0)shark[i].x -= shark[i].s;
			else
			{
				int remain = shark[i].s - shark[i].x;
				int result = remain / (c - 1);
				remain %= (c - 1);
				if (result % 2 == 1)
				{
					if (remain == 0)shark[i].d = 3;
					shark[i].x = c - remain - 1;
				}
				else
				{
					shark[i].x = remain;
					shark[i].d = 3;
				}
			}
		}
		if (board[shark[i].y][shark[i].x] != 0)
		{
			int num = board[shark[i].y][shark[i].x];
			if (shark[num].z > shark[i].z)
			{
				shark[i].alive = false;
			}
			else
			{
				board[shark[i].y][shark[i].x] = i;
				shark[num].alive = false;
			}
		}
		else
		{
			board[shark[i].y][shark[i].x] = i;
		}
	}
	//PrintBoard();
}
int CatchShark(int x)
{
	for (int i = 0; i < r; i++)
	{
		if (board[i][x] != 0)
		{
			shark[board[i][x]].alive = false;
			//cout << "Catch : " << board[i][x] << " Get : " << shark[board[i][x]].z << "\n";
			return shark[board[i][x]].z;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c >> m;
	for (int i = 1; i <= m; i++)
	{
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		shark[i] = Shark(y - 1, x - 1, s, d, z);
		board[y - 1][x - 1] = i;
	}
	int result = 0;
	for (int i = 0; i < c; i++)
	{
		result += CatchShark(i);
		MoveShark();
	}
	cout << result;
}