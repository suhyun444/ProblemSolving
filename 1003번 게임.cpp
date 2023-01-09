#include <iostream>
#include <cstring>

using namespace std;

int n, m;
char board[51][51];
int cache[51][51];
bool visited[51][51];
int solve(int y,int x)
{
	if (board[y][x] == 'H')return 0;
	if (y < 0 || y >= n || x < 0 || x >= m)return 0;

	int& ret = cache[y][x];
	if (ret != -1)return ret;
	if (visited[y][x])return 1e9;
	visited[y][x] = true;
	int num = board[y][x] - '0';
	ret = max(max(solve(y + num, x) + 1, solve(y, x + num) + 1), max(solve(y - num, x) + 1, solve(y, x - num) + 1));
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
	int result = solve(0, 0);
	if (result >= 1e9)
		cout << "-1";
	else
		cout << result;
}