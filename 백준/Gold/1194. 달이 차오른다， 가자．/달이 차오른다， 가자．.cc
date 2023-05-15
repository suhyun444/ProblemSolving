#include <iostream>
#include <queue>

using namespace std;

int n, m;
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,-1,0,1 };
bool visited[51][51][2 << 5];
char board[51][51];
int bfs(int y,int x)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ {y,x},0 });
	visited[y][x][0] = true;
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<pair<int, int>, int> cur = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nextY = cur.first.first + dirY[j];
				int nextX = cur.first.second + dirX[j];
				if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
				{
					if (!visited[nextY][nextX][cur.second])
					{
						if ('A' <= board[nextY][nextX] && board[nextY][nextX] <= 'F')
						{
							if (((cur.second >> (board[nextY][nextX] - 'A')) & 1) == 1)
							{
								visited[nextY][nextX][cur.second] = true;
								q.push({ {nextY,nextX},cur.second });
							}
						}
						else if ('a' <= board[nextY][nextX] && board[nextY][nextX] <= 'f')
						{
							visited[nextY][nextX][cur.second] = true;
							q.push({ {nextY,nextX},(cur.second | (1 << (board[nextY][nextX] - 'a'))) });
						}
						else if (board[nextY][nextX] == '.')
						{
							visited[nextY][nextX][cur.second] = true;
							q.push({ {nextY,nextX},cur.second });
						}
						else if (board[nextY][nextX] == '1')
						{
							return level + 1;
						}
					}
				}
			}
		}
		level++;
	}
	return -1;
}
int main()
{
	int y,x;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == '0')
			{
				board[i][j] = '.';
				y = i;
				x = j;
			}
		}
	}
	cout << bfs(y, x);
}