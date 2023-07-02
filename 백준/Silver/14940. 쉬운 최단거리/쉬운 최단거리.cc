#include <iostream>
#include <queue>

using namespace std;

int n, m;
int visited[1001][1001];
int board[1001][1001];
int startY, startX;
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
void bfs()
{
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)visited[i][j] = 2e9;
	queue<pair<int, int>> q;
	q.push({ startY,startX });
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> cur = q.front();
			q.pop();
			if (visited[cur.first][cur.second] != 2e9)
				continue;
			visited[cur.first][cur.second] = level;
			for (int j = 0; j < 4; j++)
			{
				int nextY = cur.first + dirY[j];
				int nextX = cur.second + dirX[j];
				if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
				{
					if (board[nextY][nextX] == 1)
					{
						q.push({ nextY,nextX });
					}
				}
			}
		}
		level++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				startY = i;
				startX = j;
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
				cout << "0 ";
			else if (visited[i][j] == 2e9)
				cout << "-1 ";
			else
				cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}