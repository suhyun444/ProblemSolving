#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[32001];
int indegree[32001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		indegree[b]++;
		adj[a].push_back(b);
	}
	priority_queue<int,vector<int>,greater<int>> q;
	for (int i = 1; i <= n; i++)if (indegree[i] == 0)q.push(i);
	int result[32001];
	for (int i = 0; i < n; i++)
	{
		int cur = q.top();
		q.pop();
		result[i] = cur;
		for (int next : adj[cur])
			if (--indegree[next] == 0)q.push(next);
	}
	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
}