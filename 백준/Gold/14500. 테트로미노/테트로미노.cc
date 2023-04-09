#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int ans = 0;
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { 1,-1,0,0 };
int dirXThree[4][4] = { {0,0,0,1},{0,0,0,-1},{-1,0,1,0},{-1,0,1,0} };
int dirYThree[4][4] = { {1,0,-1,0},{1,0,-1,0},{0,0,0,1},{0,0,0,-1} };
int board[501][501];
bool visited[501][501];
void dfs(int y, int x, int length,int sum)
{
	sum += board[y][x];
	if (length == 4)
	{
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dirY[i];
		int nextX = x + dirX[i];
		if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n)
		{
			if (!visited[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				dfs(nextY, nextX, length + 1, sum);
				visited[nextY][nextX] = false;
			}
		}
	}
}
void checkThree(int y,int x)
{
	for (int i = 0; i < 4; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			int nextY = y + dirYThree[i][j];
			int nextX = x + dirXThree[i][j];
			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
			{
				sum = 0;
				continue;
			}
			sum += board[nextY][nextX];
		}
		ans = max(ans, sum);
	}
}
void dfsAll()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = true;
			dfs(i, j, 1, 0);
			visited[i][j] = false;
			checkThree(i, j);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	dfsAll();
	cout << ans;
}