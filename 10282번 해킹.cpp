#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool visited[10001];
	int t;
	cin >> t;	
	while (t--)
	{
		memset(visited, false, sizeof(visited));
		vector<pair<int, int>> adj[10001];
		int n, d, c;
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].push_back({ a,s });
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0,c });
		int result = 0;
		int hackedNumber = 0;
		while (!pq.empty())
		{
			pair<int, int> cur = pq.top();
			pq.pop();
			if (visited[cur.second])continue;
			visited[cur.second] = true;
			result = max(result, cur.first);
			hackedNumber++;
			for (pair<int, int> next : adj[cur.second])
			{
				int curTime = cur.first;
				int cost = next.second;
				int nextNode = next.first;
				if (!visited[nextNode])
				{
					pq.push({ curTime + cost,nextNode });
				}
			}
		}
		cout << hackedNumber << " " << result << "\n";
	}
}