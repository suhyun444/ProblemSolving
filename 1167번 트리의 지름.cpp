#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> adj[100001];
bool visited[100001];
long long maxDist = 0;
int maxNode = 0;
void dfs(int cur, long long weight)
{
	visited[cur] = true;
	if (weight > maxDist)
	{
		maxDist = weight;
		maxNode = cur;
	}
	for (pair<int, int> next : adj[cur])
	{
		if (visited[next.first])continue;
		visited[next.first] = true;
		dfs(next.first, weight + next.second);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v;
	cin >> v;
	for (int i = 0; i < v; i++)
	{
		int a;
		cin >> a;
		while (true)
		{
			int b,c;
			cin >> b;
			if (b == -1)break;
			cin >> c;
			adj[a].push_back({ b,c });
		}
	}
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(maxNode,0);
	cout << maxDist;
}