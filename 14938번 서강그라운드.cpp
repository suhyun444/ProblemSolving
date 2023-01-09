#include <iostream>
#include <vector>

using namespace std;

int n, m, r;
int items[101];
int dists[101];
vector<pair<int, int>> adj[101];
void Dfs(int cur,int dist)
{
	for (pair<int,int> next : adj[cur])
	{
		if (dist + next.second <= m)
		{
			if (dists[next.first] > dist + next.second)
			{
				dists[next.first] = dist + next.second;
				Dfs(next.first, dist + next.second);
			}
		}
	}

}
int DfsAll()
{
	int maxItem = 0;
	for (int i = 1; i <= n; i++)
	{
		int curItem = 0;
		for (int j = 0; j <= n; j++)dists[j] = 2e9;
		dists[i] = 0;
		Dfs(i, 0);
		for (int j = 0; j <= n; j++)
		{
			if (dists[j] != 2e9)
				curItem += items[j];
		}
		maxItem = max(maxItem, curItem);
	}
	return maxItem;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}
	for (int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	cout << DfsAll();
}