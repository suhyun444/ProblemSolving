#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int board[51][51];
bool visited[51][51];
int dirX[4] = { -1,0,1,0 };
int dirY[4] = { 0,-1,0,1 };
int dfs(int curY,int curX)
{
	int num = 1;
	visited[curY][curX] = true;
	for (int i = 3; i >= 0; i--)
	{
		if ((board[curY][curX] & (1 << i)) == 0)
		{
			int nextY = curY + dirY[i];
			int nextX = curX + dirX[i];
			if (0 <= nextY && nextY < m && 0 <= nextX && nextX < n)
			{
				if (!visited[nextY][nextX])
				{
					num += dfs(nextY, nextX);
				}
			}
		}
	}
	return num;
}
pair<int,int> dfsAll()
{
	memset(visited, false, sizeof(visited));
	int numberOfRooms = 0;
	int maxArea = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				numberOfRooms++;
				maxArea = max(maxArea,dfs(i, j));
			}
		}
	}
	return { numberOfRooms, maxArea };
}
int TryAllPossibility()
{
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if ((board[i][j] & (1 << k)) != 0)
				{
					board[i][j] = board[i][j] & ~(1 << k);
					result = max(result,dfsAll().second);
					board[i][j] = board[i][j] | (1 << k);
				}
			}
		}
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	pair<int, int> result = dfsAll();
	cout << result.first << "\n";
	cout << result.second << "\n";
	cout << TryAllPossibility() << "\n";
}