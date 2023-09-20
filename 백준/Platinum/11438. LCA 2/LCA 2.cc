#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int parent[100001][18];
int depth[100001];
vector<int> adj[100001];
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
	int n, m;
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	depth[1] = 0;
	cin >> n;
	for (int i = 0; i < n-1; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for(int j=0;j<17;++j)
		for (int i = 1; i <= n; ++i)
			if(parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
	
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (depth[a] < depth[b])swap(a, b);
		int diff = depth[a] - depth[b];
		int index = 0;
		while (diff > 0)
		{
			if (diff % 2 == 1)a = parent[a][index];
			diff /= 2;
			++index;
		}
		if (a != b)
		{
			for (int j = 17; j >= 0; --j)
			{
				if (parent[a][j] != -1 && parent[a][j] != parent[b][j])
				{
					a = parent[a][j];
					b = parent[b][j];
				}
			}
			a = parent[a][0];
		}
		cout << a << "\n";
	}
}