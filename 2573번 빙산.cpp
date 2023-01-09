#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
int board[301][301];
int nextBoard[301][301];
bool visited[301][301];
int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };
void melt()
{
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)nextBoard[i][j] = board[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != 0)
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{ 
					int nextY = i + dirY[k];
					int nextX = j + dirX[k];
					if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
					{
						if (board[nextY][nextX] == 0)
						{
							cnt++;
						}
					}
				}
				nextBoard[i][j] -= cnt;
				nextBoard[i][j] = max(nextBoard[i][j], 0);
			}
		}
	}
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)board[i][j] = nextBoard[i][j];
}
void dfs(int curY,int curX)
{
	visited[curY][curX] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextY = curY + dirY[i];
		int nextX = curX + dirX[i];
		if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
		{
			if (!visited[nextY][nextX] && board[nextY][nextX] != 0)
			{
				dfs(nextY, nextX);
			}
		}
	}
}
int dfsAll()
{
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && board[i][j] != 0)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int result = 1;
	while (true)
	{
		melt();
		int islandCount = dfsAll();
		if (islandCount > 1)
		{
			cout << result;
			return 0;
		}
		if (islandCount == 0)
		{
			cout << "0";
			return 0;
		}
		result++;
	}
}