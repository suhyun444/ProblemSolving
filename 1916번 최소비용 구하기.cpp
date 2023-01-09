#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[1001];
vector<pair<int, int>> adj[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int dist[1001];

	for (int i = 0; i < 1001; i++)dist[i] = 1e9;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int start, end;
	cin >> start >> end;
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty())
	{
		pair<int,int> cur = pq.top();
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
			if (dist[next.first] > dist[cur.second] + next.second)
			{
				dist[next.first] = dist[cur.second] + next.second;
				pq.push({ dist[next.first],next.first });
			}
		}
		
	}
	cout << dist[end];
}