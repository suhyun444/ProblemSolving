#include <iostream>
#include <queue>

using namespace std;

int n, m;
char board[51][51];
bool visited[1<<2][4][51][51];
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
int bfs(int startY,int startX)
{
	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,-1},{startY,startX} });
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			pair<pair<int, int>, pair<int, int>> cur = q.front();
			q.pop();
			for (int j = 0; j < 4; ++j)
			{
				if (j == cur.first.second)continue;
				int nextY = cur.second.first + dirY[j];
				int nextX = cur.second.second + dirX[j];
				if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
				{
					if (!visited[cur.first.first][j][nextY][nextX])
					{
						if (board[nextY][nextX] == '.')
						{
							 q.push({ {cur.first.first,j} ,{nextY,nextX} });
						}
						else if ('0' <= board[nextY][nextX] && board[nextY][nextX] <= '9')
						{
							int nextKey = cur.first.first | 1 << (int)(board[nextY][nextX] - '0');
							if (nextKey == 3)
							{
								return level + 1;
							}
							q.push({ {nextKey,j} ,{nextY,nextX} });
						}
						visited[cur.first.first][j][nextY][nextX] = true;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int index = 0;
	int startY, startX;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 'S')
			{
				startY = i;
				startX = j;
				board[i][j] = '.';
			}
			if (board[i][j] == 'C')
			{
				board[i][j] = (char)index + '0';
				++index;
			}
		}
	}
	cout << bfs(startY, startX);
}