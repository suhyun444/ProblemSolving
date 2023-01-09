#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int indegree[101];
int numOfMake[101];
vector<pair<int, int>> adj[101];
vector<int> v;
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
		indegree[b]++;
	}
	queue<int> q;
	q.push(n);
	numOfMake[n] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (adj[cur].empty())
		{
			v.push_back(cur);
		}
		for (pair<int, int> next : adj[cur])
		{
			numOfMake[next.first] += numOfMake[cur] * next.second;
			if (--indegree[next.first] == 0)
			{
				q.push(next.first);
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " " << numOfMake[v[i]] << "\n";
	}
}