#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int parent[30001][16];
int depth[30001];
vector<int> adj[30001];
void dfs(int cur)
{
	for (int next : adj[cur])
	{
		if (depth[next] == -1)
		{
			depth[next] = depth[cur] + 1;
			parent[next][0] = cur;
			dfs(next);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	depth[1] = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for (int j = 0; j < 16; ++j)
		for (int i = 1; i <= n; ++i)
			if(parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
	int m;
	cin >> m;
	int prev;
	cin >> prev;
	int result = 0;
	for (int i = 0; i < m - 1; ++i)
	{
		int cur;
		cin >> cur;
		int a = prev, b = cur;
		if (depth[a] < depth[b])swap(a, b);
		int diff = depth[a] - depth[b];
		int index = 0;
		while (diff > 0)
		{
			if (diff % 2 == 1)
			{
				a = parent[a][index];
				result += 1 << index;
			}
			diff /= 2;
			++index;
		}
		if (a != b)
		{
			for (int j = 15; j >= 0; --j)
			{
				if (parent[a][j] != -1 && parent[a][j] != parent[b][j])
				{
					result += 1 << j;
					result += 1 << j; 
					a = parent[a][j];
					b = parent[b][j];
				}
			}
			result += 2;
		}
		prev = cur;
	}
	cout << result;
}