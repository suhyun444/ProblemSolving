#include <iostream>
#include <vector>
#include <queue>


using namespace std;

long long dist[21][10001];
bool visited[21][10001];
vector<pair<int, long long>> adj[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 21; i++)for (int j = 0; j < 10001; j++)dist[i][j] = 9223372036854775800;
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	priority_queue < pair<long long, pair<int, int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>> pq;
	pq.push({ 0,{0,1} });
	while (!pq.empty())
	{
		pair<long long, pair<int, int>> cur = pq.top();
		pq.pop();
		if (visited[cur.second.first][cur.second.second])continue;
		visited[cur.second.first][cur.second.second] = true;
		for (pair<int, int> next : adj[cur.second.second])
		{
			long long cost = cur.first + next.second;
			if (dist[cur.second.first][next.first] > cost)
			{
				dist[cur.second.first][next.first] = cost;
				pq.push({ dist[cur.second.first][next.first],{cur.second.first,next.first} });
			}
			if (cur.second.first + 1 <= k && dist[cur.second.first + 1][next.first] > cur.first)
			{
				dist[cur.second.first + 1][next.first] = cur.first;
				pq.push({ dist[cur.second.first + 1][next.first],{cur.second.first + 1,next.first} });
			}
		}
	}
	long long result = 9223372036854775800;
	for (int i = 0; i <= k; i++)
	{
		result = min(result, dist[i][n]);
	}
	cout << result;
}