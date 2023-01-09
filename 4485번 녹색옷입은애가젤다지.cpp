#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dirY[4] = { 0,0,-1,1 };
int dirX[4] = { 1,-1,0,0 };
int dist[126][126];
bool visited[126][126];
int board[126][126];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 1;
	while(true)
	{ 
		int n;
		cin >> n;
		if (n == 0)return 0;
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			dist[i][j] = 1e9;
			visited[i][j] = false;
		}
		priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push({ board[0][0],{0,0} });
		dist[0][0] = 0;
		while (!pq.empty())
		{
			int curDistance = pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			pq.pop();
			while (!pq.empty() && visited[y][x])
			{
				curDistance = pq.top().first;
				y = pq.top().second.first;
				x = pq.top().second.second;
				pq.pop();
			}
			if (visited[y][x])break;
			visited[y][x] = true;
			for (int i = 0; i < 4; i++)
			{
				int nextY = y + dirY[i];
				int nextX = x + dirX[i];
				if (!visited[nextY][nextX])
				{
					if (dist[nextY][nextX] > curDistance + board[nextY][nextX])
					{
						dist[nextY][nextX] = curDistance + board[nextY][nextX];
						pq.push({ dist[nextY][nextX],{nextY,nextX} });
					}
				}
			}
		}
		cout << "Problem " << cnt++ << ": " << dist[n - 1][n - 1] << "\n";
	}
}