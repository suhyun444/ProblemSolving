#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>> adj[40001];
int foxDist[4001];
int wolfDist[4001][2];
bool foxVisited[4001];
bool visited[4001][2];
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
	fill(foxDist, foxDist + n + 1, 1e9);
	for (int i = 0; i < 2; i++)for (int j = 0; j <= n; j++)wolfDist[j][i] = 1e9;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	foxDist[1] = 0;
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();
		while (!pq.empty() && foxVisited[cur.second])
		{
			cur = pq.top();
			pq.pop();
		}
		if (foxVisited[cur.second]) break;
		foxVisited[cur.second] = true;
		for (pair<int, int> next : adj[cur.second])
		{
			int cost = next.second * 2;
			int nextPosition = next.first;
			if (foxDist[nextPosition] > foxDist[cur.second] + cost)
			{
				foxDist[nextPosition] = foxDist[cur.second] + cost;
				pq.push({ foxDist[nextPosition],nextPosition });
			}
		}
	}
	memset(visited, false, sizeof(visited));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> wolfPq;
	wolfPq.push({ 0,{1,0} });
	wolfDist[1][0] = 0;
	while (!wolfPq.empty())
	{
		pair<int, pair<int, int>> cur = wolfPq.top();
		wolfPq.pop();
		while (!wolfPq.empty() && visited[cur.second.first][cur.second.second])
		{
			cur = wolfPq.top();
			wolfPq.pop();
		}
		if (visited[cur.second.first][cur.second.second])break;
		visited[cur.second.first][cur.second.second] = true;
		for (pair<int, int> next : adj[cur.second.first])
		{
			int cost = (cur.second.second == 0) ? next.second : next.second * 4;
			int nextPosition = next.first;
			if (wolfDist[nextPosition][!cur.second.second] > wolfDist[cur.second.first][cur.second.second] + cost)
			{
				wolfDist[nextPosition][!cur.second.second] = wolfDist[cur.second.first][cur.second.second] + cost;
				wolfPq.push({ wolfDist[nextPosition][!cur.second.second],{nextPosition,!cur.second.second}});
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (foxDist[i] < min(wolfDist[i][0],wolfDist[i][1]))
		{
			result++;
		}
	}
	cout << result;
}