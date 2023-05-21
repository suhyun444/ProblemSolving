#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> adj[2001];
bool visited[2001];
int dfs(int cur, int depth)
{
	if (depth == 5)return depth;
	int ret = depth;

	for (int next : adj[cur])
	{
		if (!visited[next])
		{
			visited[next] = true;
			ret = max(ret,dfs(next, depth + 1));
			visited[next] = false;
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		if (dfs(i, 1) >= 5)
		{
			cout << "1";
			return 0;
		}
		visited[i] = false;
	}
	cout << "0";
}