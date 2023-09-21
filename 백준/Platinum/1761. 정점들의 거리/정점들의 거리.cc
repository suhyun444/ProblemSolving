#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> adj[40001];
pair<int,int> parent[40001][17];
int depth[40001];
void dfs(int cur)
{
	for (pair<int,int> next : adj[cur])
	{
		if (depth[next.first] == -1)
		{
			depth[next.first] = depth[cur] + 1;
			parent[next.first][0] = { cur,next.second };
			dfs(next.first);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	for (int i = 0; i < 40001; ++i)for (int j = 0; j < 16; ++j)parent[i][j] = { -1,0 };
	memset(depth, -1, sizeof(depth));
	depth[1] = 0;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dfs(1);
	for (int j = 0;j<16; ++j)
		for (int i = 1; i <= n; ++i)
			if (parent[i][j].first != -1)
				parent[i][j + 1] = { parent[parent[i][j].first][j].first ,parent[i][j].second + parent[parent[i][j].first][j].second};
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		int result = 0;
		cin >> a >> b;
		if (depth[a] < depth[b])swap(a, b);
		int diff = depth[a] - depth[b];
		int index = 0;
		while (diff > 0)
		{
			if (diff % 2 == 1)
			{
				result += parent[a][index].second;
				a = parent[a][index].first;
			}
			diff /= 2;
			index++;
		}
		if (a != b)
		{
			for (int j = 16; j >= 0; --j)
			{
				if (parent[a][j].first != -1 && parent[a][j].first != parent[b][j].first)
				{
					result += parent[a][j].second;
					result += parent[b][j].second;
					a = parent[a][j].first;
					b = parent[b][j].first;
				}
			}
			result += parent[a][0].second;
			result += parent[b][0].second;
		}
		cout << result << "\n";
	}
}