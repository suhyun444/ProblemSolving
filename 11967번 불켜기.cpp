#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[101][101];
bool board[101][101];
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { 1,-1,0,0 };
vector<pair<int, int>> switchs[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		switchs[a][b].push_back({ c,d });
	}
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visited[1][1] = true;
	board[1][1] = true;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		bool isOn = false;
		for (int i = 0; i < switchs[cur.first][cur.second].size(); i++)
		{
			if (!board[switchs[cur.first][cur.second][i].first][switchs[cur.first][cur.second][i].second])
			{
				board[switchs[cur.first][cur.second][i].first][switchs[cur.first][cur.second][i].second] = true;
				isOn = true;
			}
		}
		if (isOn)
		{
			memset(visited, false, sizeof(visited));
			visited[cur.first][cur.second] = true;
			while (!q.empty())q.pop();
		}
		for (int i = 0; i < 4; i++)
		{
			int nextX = cur.first + dirX[i];
			int nextY = cur.second + dirY[i];
			if (0 < nextX && nextX <= n && 0 < nextY && nextY <= n)
			{
				if (!visited[nextX][nextY] && board[nextX][nextY])
				{
					q.push({ nextX,nextY });
					visited[nextX][nextY] = true;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)if (board[i][j])cnt++;
	cout << cnt;
}