#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int greats[100001];
int adj[100001];
int cache[100001];
int dfs(int cur)
{
	if (adj[cur] == -1)
	{
		return 0;
	}
	int& ret = cache[cur];
	if (ret != -1)return ret;
	return ret = dfs(adj[cur]) + greats[cur];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		adj[i] = a;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		greats[a] += b;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dfs(i) << " ";
	}
}