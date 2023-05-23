#include <iostream>
#include <queue>

using namespace std;


int n, m;
int objectCount;
char board[51][51];
bool visited[51][51][1 << 5];
int dirY[4] = { 0,-1,0,1 };
int dirX[4] = { 1,0,-1,0 };
int bfs(int startY,int startX)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ {startY,startX},0 });
	visited[startY][startX][0] = true;
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
						if (board[nextY][nextX] == '.')
						{
							q.push({ {nextY,nextX},cur.second });
							visited[nextY][nextX][cur.second] = true;
						}
						else if ('0' <= board[nextY][nextX] && board[nextY][nextX] <= '4')
						{
							q.push({ {nextY,nextX},(cur.second | (1 << (board[nextY][nextX] - '0')))});
							visited[nextY][nextX][cur.second] = true;
						}
						else if (board[nextY][nextX] == 'E' && cur.second == (1 << objectCount) - 1)
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int startY, startX;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'S')
			{
				startY = i;
				startX = j;
				board[i][j] = '.';
			}
			if (board[i][j] == 'X')
			{
				board[i][j] = objectCount + '0';
				objectCount++;
			}
		}
	}
	cout << bfs(startY, startX);
}