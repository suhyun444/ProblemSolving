#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int cache[3][1001][1001];
int board[1001][1001];
//stat == 0 다 가능
//stat == 1 오른쪽 이동 불가능
//stat == 2 왼쪽 이동 불가능
int solve(int stat, int y, int x)
{
	if (y == n - 1 && x == m - 1)
	{
		return board[y][x];
	}
	if (y < 0)return -1e9;
	if (x < 0 || x >= m) return -1e9;
	int& ret = cache[stat][y][x];
	if (ret != -1)return ret;
	ret = -1e9;
	if (stat == 0)
	{
		if (y + 1 < n)ret = max(ret, solve(0, y + 1, x) + board[y][x]);
		if (x - 1 >= 0)ret = max(ret, solve(1, y, x - 1) + board[y][x]);
		if (x + 1 < m)ret = max(ret, solve(2, y, x + 1) + board[y][x]);
	}
	else if (stat == 1)
	{
		if (y + 1 < n)ret = max(ret, solve(0, y + 1, x) + board[y][x]);
		if (x - 1 >= 0)ret = max(ret, solve(1, y, x - 1) + board[y][x]);
	}
	else if (stat == 2)
	{
		if (y + 1 < n)ret = max(ret, solve(0, y + 1, x) + board[y][x]);
		if (x + 1 < m)ret = max(ret, solve(2, y, x + 1) + board[y][x]);
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	cout << solve(0,0, 0);
}