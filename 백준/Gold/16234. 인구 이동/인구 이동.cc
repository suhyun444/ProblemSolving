#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int n, l, r;
int board[51][51];
bool visited[51][51];
int dirY[4] = { 1,0,-1,0 };
int dirX[4] = { 0,1,0,-1 };
bool CanLink(int y1, int x1, int y2, int x2)
{
	int diff = abs(board[y1][x1] - board[y2][x2]);
	if (l <= diff && diff <= r)
		return true;
	return false;
}
bool Bfs(int y,int x)
{
	vector<pair<int, int>> answer;
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		answer.push_back(cur);
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = cur.first + dirY[i];
			int nextX = cur.second + dirX[i];
			if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
			{
				if (!visited[nextY][nextX] && CanLink(cur.first, cur.second, nextY, nextX))
				{
					visited[nextY][nextX] = true;
					q.push({ nextY,nextX });
				}
			}
		}
	}
	if (answer.size() == 1)return false;
	int sum = 0;
	for (int i = 0; i < answer.size(); i++)
		sum += board[answer[i].first][answer[i].second];
	sum /= answer.size();
	for (int i = 0; i < answer.size(); i++)
		board[answer[i].first][answer[i].second] = sum;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int result = 0;
	while (true)
	{
		bool isFinish = true;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && Bfs(i, j))
				{
					isFinish = false;
				}
			}
		}
		if (isFinish)break;
		result++;
	}
	cout << result;
}
