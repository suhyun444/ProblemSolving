#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, w;
		vector<pair<int, int>> adj[501];
		int dist[501];
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });
		}
		for (int i = 0; i < w; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({ b,-c });
		}
		bool canTimeWarp = false;
		for (int i = 0; i < 501; i++)dist[i] = 1e9;
		dist[1] = 0;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (pair<int, int> next : adj[j])
				{
					int nextNode = next.first, distance = next.second;
					if (dist[nextNode] > dist[j] + distance)
					{
						dist[nextNode] = dist[j] + distance;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (pair<int, int> next : adj[i])
			{
				int nextNode = next.first, distance = next.second;
				if (dist[i] != 1e9 && dist[nextNode] > dist[i] + distance)
				{
					canTimeWarp = true;
				}
			}
			if (canTimeWarp)break;
		}
		if (!canTimeWarp)cout << "NO\n";
		else cout << "YES\n";
	}
}