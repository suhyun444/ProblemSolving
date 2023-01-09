#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	pair<int,vector<int>> dist[1001];
	bool visited[1001];
	for (int i = 0; i < 1001; i++)
	{
		dist[i].first = 1e9;
		visited[i] = false;
	}
	int start, end;
	cin >> start >> end;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });
	dist[start].first = 0;
	dist[start].second.push_back(start);
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
			int nextNode = next.first;
			int distance = next.second;
			if (dist[nextNode].first > dist[cur.second].first + distance)
			{
				dist[nextNode].first = dist[cur.second].first + distance;
				dist[nextNode].second = dist[cur.second].second;
				dist[nextNode].second.push_back(nextNode);
				pq.push({ dist[nextNode].first,nextNode });
			}
		}
	}
	cout << dist[end].first << "\n";
	cout << dist[end].second.size() << "\n";
	for (int i = 0; i < dist[end].second.size(); i++)
	{
		cout << dist[end].second[i] << " ";
	}
}