#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<int> candy;
vector<int> adj[30001];
bool visited[30001];
int cache[3001];
vector<pair<int,int>> weight;
pair<int,int> dfs(int cur)
{
	pair<int, int> ret = { 1,candy[cur] };
	visited[cur] = true;
	for (int next : adj[cur])
	{
		if (!visited[next])
		{
			pair<int,int> nextRet = dfs(next);
			ret.first += nextRet.first;
			ret.second += nextRet.second;
		}
	}
	return ret;
}
void dfsAll()
{
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			weight.push_back(dfs(i));
		}
	}
}
int solve()
{
	for (int i = 0; i < weight.size(); i++)
	{
		for (int j = k - 1; j - weight[i].first >= 0; j--)
		{
			cache[j] = max(cache[j], cache[j - weight[i].first] + weight[i].second);
		}
	}
	return cache[k - 1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	candy.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		candy.push_back(a);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfsAll();
	cout << solve();
}
