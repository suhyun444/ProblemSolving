#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool findCycle = 0;
bool visited[3001];
bool cycled[3001];
int parent[3001];
vector<int> adj[3001];
void dfs(int cur)
{
	visited[cur] = true;
	for (int next : adj[cur])
	{
		if (findCycle)return;
		if (visited[next])
		{
			if (parent[cur] != next)
			{
				findCycle = true;
				for (int i = cur; i != next; i = parent[i])
					cycled[i] = true;
				cycled[next] = true;
			}
		}
		else
		{
			parent[next] = cur;
			dfs(next);
		}
	}
}
int bfs(int start)
{
	if (cycled[start])return 0;
	memset(visited, false, sizeof(visited));
	int level = 0;
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int cur = q.front();
			q.pop();
			for (int next : adj[cur])
			{
				if (!visited[next])
				{
					q.push(next);
					visited[next] = true;
					if (cycled[next])
					{
						return level + 1;
					}
				}
			}
		}
		level++;
	}
	return level;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		cout << bfs(i) << " ";
	}
}