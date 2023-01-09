#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
bool visited[101][101];
int board[101][101];
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { 1,-1,0,0 };
int ans = 2e9;
void dfs(int curY,int curX,int color)
{
	board[curY][curX] = color;
	visited[curY][curX] = true;
	for (int i = 0; i < 4; i++)
	{
		int nextY = curY + dirY[i];
		int nextX = curX + dirX[i];
		if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
		{
			if (!visited[nextY][nextX] && board[nextY][nextX] != 0)
			{
				dfs(nextY, nextX, color);
				visited[nextY][nextX] = true;
			}
		}
	}
}
void bfs(int y, int x)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {y,x},{0,board[y][x]} });
	//{y,x},{distance,color}
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
	{
		visited[i][j] = false;
	}

	while (!q.empty())
	{
		pair<pair<int, int>, pair<int, int>> cur;
		cur = q.front();
		q.pop();
		if (cur.second.first >= ans)return;
		for (int i = 0; i < 4; i++)
		{
			int nextY = cur.first.first + dirY[i];
			int nextX = cur.first.second + dirX[i];
			if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
			{
				if (!visited[nextY][nextX])
				{
					if (board[nextY][nextX] == 0)
					{
						q.push({ { nextY,nextX },{cur.second.first + 1,cur.second.second} });
					}
					else if (!visited[nextY][nextX])
					{
						if (board[nextY][nextX] != cur.second.second)
						{
							ans = min(ans, cur.second.first);
						}
						q.push({ {nextY,nextX},{0,board[nextY][nextX]} });
					}
					visited[nextY][nextX] = true;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	vector<pair<int, int>>islands;
	int color = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && board[i][j] != 0)
			{
				islands.push_back({ i,j });
				dfs(i, j, color++);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != 0)
			{
				bfs(i, j);
			}
		}
	}
	cout << ans;
}