#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[1001];
bool visited[1001];
int choice[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	int dist[1001];
	for (int i = 0; i < 1001; i++)dist[i] = 1001;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	dist[1] = 0;
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();
		while (!pq.empty() && visited[cur.second])
		{
			cur = pq.top();
			pq.pop();
		}
		if (visited[cur.second])break;
		visited[cur.second] = true;
		for (pair<int, int> next : adj[cur.second])
		{
			int distance = cur.first + next.second;
			if (dist[next.first] > distance)
			{
				dist[next.first] = distance;
				choice[next.first] = cur.second;
				pq.push({ distance, next.first});
			}
		}
	}
	cout << n - 1 << "\n";
	for (int i = 2; i <= n; i++)
	{
		cout << i << " " << choice[i] << "\n";
	}
}