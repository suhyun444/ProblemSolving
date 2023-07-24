#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n, p, k;
vector<pair<int, int>> adj[1001];
bool visited[1001];
int Dijkstra(int mid)
{
	memset(visited, false, sizeof(visited));
	int dist[1001];
	for (int i = 0; i < 1001; ++i)
	{
		dist[i] = 1e9;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0,1});
	dist[1] = 0;
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();
		if (visited[cur.second])continue;
		visited[cur.second] = true;
		for (pair<int, int> next : adj[cur.second])
		{
			int cost = cur.first + (next.second > mid);
			if (dist[next.first] > cost)
			{
				dist[next.first] = cost;
				pq.push({ cost,next.first });
			}
		}
	}
	return dist[n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> p >> k;
	for (int i = 0; i < p; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	int lo = -1, hi = 1e9;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (Dijkstra(mid) <= k)
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}
	if (hi == 1e9)
		cout << "-1";
	else
		cout << hi;
}