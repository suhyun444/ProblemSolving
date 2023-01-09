#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> adj[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	int start, end;
	cin >> start >> end;

	priority_queue<pair<int,int>> pq;
	int dist[100001];
	for (int i = 0; i <= n; i++)dist[i] = 0;
	pq.push({2e9, start });
	dist[start] = 2e9;
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();
		if (dist[cur.second] > cur.first) continue;
		for (pair<int,int> next : adj[cur.second])
		{
			int canWeight = min(next.second, cur.first);
			if (canWeight > dist[next.first])
			{
				dist[next.first] = canWeight;
				pq.push({ canWeight,next.first });
			}
		}
	}
	cout << dist[end];
}