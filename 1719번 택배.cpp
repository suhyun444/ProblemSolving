#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[201];
int dist[201];
int choice[201];
vector<pair<int, int>> adj[201];
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
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++) dist[j] = 1e9;
		for (int j = 0; j <= n; j++)visited[j] = false;
		priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push({ 0, i });
		dist[i] = 0;
		while (!pq.empty())
		{
			int cur;
			do {
				cur = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visited[cur]);
			if (visited[cur])break;
			visited[cur] = true;

			for (pair<int, int> node : adj[cur])
			{
				int distance = node.second;
				int next = node.first;
				if (dist[next] > dist[cur] + distance)
				{
					dist[next] = dist[cur] + distance;
					choice[next] = cur;
					pq.push({ dist[next],next });
				}
			}
		}
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				cout << "- ";
				continue;
			}
			int curIndex = j;
			while (choice[curIndex] != i)
			{
 				curIndex = choice[curIndex];
			}
			cout << curIndex << " ";
		}
		cout << "\n";
	}
}