#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, k;
bool visited[1002][1002];
int board[1002][1002];
int dirY[4] = { 0,0,-1,1 };
int dirX[4] = { 1,-1,0,0 };
int func(int mid)
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 1; i <= m; i++)
	{
		q.push({ 1,i });
		visited[1][i] = true;
	}
	for (int i = 2; i <= n; i++)
	{
		visited[i][1] = true;
		q.push({ i,1 });
		visited[i][m] = true;
		q.push({ i,m });
	}
	int ret = 0;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		if (board[cur.first][cur.second] <= mid)ret++;
		else continue;

		for (int i = 0; i < 4; i++)
		{
			int nextY = cur.first + dirY[i];
			int nextX = cur.second + dirX[i];
			if (0 <= nextX && nextX <= m + 1 && 0 <= nextY && nextY <= n + 1)
			{
				if (board[nextY][nextX] != 0 && !visited[nextY][nextX])
				{
					q.push({ nextY,nextX });
					visited[nextY][nextX] = true;
				}
			}
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	int lo = 1;
	int hi = 1e6;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		int d = func(mid);
		if (d < k)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << hi;
}