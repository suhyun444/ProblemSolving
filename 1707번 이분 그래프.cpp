#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int v, e;
vector<int> adj[20001];
bool visited[20001];
int color[20001];
bool dfs(int cur,int state)
{
	bool isBipartite = false;
	visited[cur] = true;
	color[cur] = state;
	for (int next : adj[cur])
	{
		if (color[cur] == color[next])return true;
		if (!visited[next])
		{
			visited[next] = true;
			if (dfs(next, !state))
				isBipartite = true;
		}
	}
	return isBipartite;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		memset(color, -1, sizeof(color));
		memset(visited, false, sizeof(visited));
		cin >> v >> e;
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool isBipartite = false;
		for (int i = 1; i <= v; i++)
		{
			if (!visited[i])
			{
				if (dfs(i, 0))
					isBipartite = true;
			}
		}
		if (!isBipartite)cout << "YES\n";
		else cout << "NO\n";
		for (int i = 1; i <=v; i++)adj[i].clear();
		
	}
}