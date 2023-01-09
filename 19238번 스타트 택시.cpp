#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, fuel,y,x;
int board[21][21];
bool visited[21][21];
vector < pair<int,int> >people;
int dirY[4] = { 0,0,-1,1 };
int dirX[4] = { 1,-1,0,0 };
pair<pair<pair<int, int>, pair<int, int>>, int> GetNearestPeople()
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	int level = 0;
	vector< pair<pair<pair<int, int>, pair<int, int>>, int>> v;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			pair<int, int> cur = q.front();
			q.pop();
			if (board[cur.first][cur.second] != -2)
			{
				int index = board[cur.first][cur.second];
				v.push_back({ {{cur.first,cur.second},people[index]},level});
			}
			for (int i = 0; i < 4; i++)
			{
				int nextY = cur.first + dirY[i];
				int nextX = cur.second + dirX[i];
				if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
				{
					if (!visited[nextY][nextX] && (board[nextY][nextX] != -1))
					{
						q.push({ nextY,nextX });
						visited[nextY][nextX] = true;

					}
				}
			}
		}
		if (v.size() != 0)
		{
			sort(v.begin(), v.end());
			board[v[0].first.first.first][v[0].first.first.second] = -2;
			return v[0];
		}
		level++;
	}
	return { { {2e9,0},{0,0,} }, 0 };
}
void bfs()
{
	queue < pair<int, int>> q;
	for (int i = 0; i < m; i++)
	{
		pair<pair<pair<int, int>, pair<int, int>>, int> target = GetNearestPeople();
		if (target.first.first.first == 2e9)
		{
			fuel = -1;
			return;
		}
		pair<int, int> targetPos = target.first.first;
		pair<int, int> goalPos = target.first.second;
		int usedFuel = target.second;
		fuel -= usedFuel;
		usedFuel = 0;
		if (fuel <= 0)
		{
			fuel = -1;
			return;
		}
		memset(visited, false, sizeof(visited));
		q.push({ targetPos.first, targetPos.second });
		visited[targetPos.first][targetPos.second] = true;
		bool isGoal = false;
		if (targetPos != goalPos)
		{
			while (!q.empty())
			{
				int size = q.size();
				while (size--)
				{
					pair<int, int> cur = q.front();
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						int nextY = cur.first + dirY[i];
						int nextX = cur.second + dirX[i];
						if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
						{
							if (nextY == goalPos.first && nextX == goalPos.second)
							{
								isGoal = true;
								break;
							}
							if (!visited[nextY][nextX] && board[nextY][nextX] != -1)
							{
								q.push({ nextY,nextX });
								visited[nextY][nextX] = true;
							}
						}
					}
					if (isGoal)break;
				}
				usedFuel++;
				if (isGoal) break;
			}
		}
		if (fuel - usedFuel < 0 || !isGoal)
		{
			fuel = -1;
			return;
		}
		while (!q.empty())q.pop();
		fuel += usedFuel;
		y = goalPos.first;
		x = goalPos.second;
	}
}
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> fuel;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			board[i][j] -= 2;
		}
	}
	cin >> y >> x;
	y--; x--;
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		board[a][b] = i;
		people.push_back({c,d});
	}
	bfs();
	cout << fuel;
}