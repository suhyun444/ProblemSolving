#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>> adj[2001];
vector<int> list;
int dist[2001];
int gDist[2001];
int hDist[2001];
bool visited[2001];
void dijkstra(int s,int type)
{
	memset(visited, false, sizeof(visited));
	priority_queue < pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	visited[s] = 0;
	if (type == 0)	dist[s] = 0;
	else if (type == 1)gDist[s] = 0;
	else if (type == 2)hDist[s] = 0;
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();
		while (!pq.empty() && visited[cur.second])
		{
			cur = pq.top();
			pq.pop();
		}
		if (visited[cur.second])
			break;
		visited[cur.second] = true;
		for (pair<int, int> next : adj[cur.second])
		{
			int distance = next.second;
			if (type == 0)
			{
				if (dist[next.first] >= cur.first + distance)
				{
					dist[next.first] = cur.first + distance;
					pq.push({ cur.first + distance,next.first });
				}
			}
			if (type == 1)
			{
				if (gDist[next.first] >= cur.first + distance)
				{
					gDist[next.first] = cur.first + distance;
					pq.push({ cur.first + distance,next.first });
				}
			}
			if (type == 2)
			{
				if (hDist[next.first] >= cur.first + distance)
				{
					hDist[next.first] = cur.first + distance;
					pq.push({ cur.first + distance,next.first });
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin >> test;
	while (test--)
	{
		int n, m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++)
		{
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back({ b,d });
			adj[b].push_back({ a,d });
		}
		for (int i = 0; i < t; i++)
		{
			int a;
			cin >> a;
			list.push_back(a);
		}
		for (int i = 0; i < 2001; i++)
		{
			dist[i] = 1e9;
			gDist[i] = 1e9;
			hDist[i] = 1e9;
		}
		sort(list.begin(), list.end());
		dijkstra(s, 0);
		dijkstra(g, 1);
		dijkstra(h, 2);
		for (int i = 0; i < t; i++)
		{
			int e = list[i];
			if (dist[e] == dist[g] + gDist[h] + hDist[e] || dist[e] == dist[h] + hDist[g] + gDist[e])
			{
				cout << list[i] << " ";
			}
		}
		cout << "\n";
		list.clear();
		for (int i = 0; i < 2001; i++)adj[i].clear();
	}
}