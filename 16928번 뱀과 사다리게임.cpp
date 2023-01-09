#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visited[101];
int board[101];
int bfs()
{
	memset(visited, false, sizeof(visited));
	queue<int> q;
	int level = 0;
	q.push(1);
	visited[1] = level;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int cur = q.front();
			if (cur == 100)
			{
				return level;
			}
			q.pop();
			for (int j = 1; j <= 6; j++)
			{
				if (cur + j > 100 || visited[board[cur + j]])continue;
				visited[board[cur + j]] = level;
				q.push(board[cur + j]);
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
	for (int i = 0; i < 101; i++)board[i] = i;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a] = b;
		if (b > 100)board[a] = 0;
	}

	int count = bfs();
	cout << count;
}