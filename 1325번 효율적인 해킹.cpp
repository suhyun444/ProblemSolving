#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[10001];
bool visited[10001];
vector<pair<int, int>> result;
bool Compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
int dfs(int cur)
{
	if (visited[cur])return 0;
	int num = 1;
	visited[cur] = true;
	for (int next : adj[cur])
	{
		num += dfs(next);
	}
	return num;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		result.push_back({ dfs(i), i });
	}
	sort(result.begin(), result.end(), Compare);
	for (int i = 0; i < n; i++)
	{
		if (result[i].first == result[0].first)cout << result[i].second << "\n";
	}
}