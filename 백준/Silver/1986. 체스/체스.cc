#include <iostream>
#include <vector>

using namespace std;

int n, m;
int board[1001][1001];
int queenDirY[8] = { 1,1,1,0,-1,-1,-1,0 };
int queenDirX[8] = { -1,0,1,1,1,0,-1,-1 };
int knightDirY[8] = { 2,2,1,-1,-2,-2,-1,1 };
int knightDirX[8] = { -1,1,2,2,1,-1,-2,-2 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> queen;
	vector<pair<int, int>> knight;
	cin >> n >> m;
	int a;
	cin >> a;
	for (int i = 0; i < a; ++i)
	{
		int y, x;
		cin >> y >> x;
		--y; --x;
		queen.push_back({ y,x });
		board[y][x] = 1;
	}
	cin >> a;
	for (int i = 0; i < a; ++i)
	{
		int y, x;
		cin >> y >> x;
		--y; --x;
		knight.push_back({ y,x });
		board[y][x] = 1;
	}
	cin >> a;
	for (int i = 0; i < a; ++i)
	{
		int y, x;
		cin >> y >> x;
		--y; --x;
		board[y][x] = 1;
	}
	for (int i = 0; i < queen.size(); ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			int size = 1;
			while (true)
			{
				int nextY = queen[i].first + queenDirY[j] * size;
				int nextX = queen[i].second + queenDirX[j] * size;
				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || board[nextY][nextX] == 1)
					break;
				board[nextY][nextX] = 2;
				++size;
			}
		}
	}
	for (int i = 0; i < knight.size(); ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			int nextY = knight[i].first + knightDirY[j];
			int nextX = knight[i].second + knightDirX[j];
			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || board[nextY][nextX] == 1)
				continue;
			board[nextY][nextX] = 2;
		}
	}
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 0)++result;
		}
	}
	cout << result;
}