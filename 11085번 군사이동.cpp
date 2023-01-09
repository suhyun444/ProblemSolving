#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int p[1001];
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	return a.second > b.second;
}
int find(int n)
{
	if (p[n] < 0)return n;
	p[n] = find(p[n]);
	return p[n];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(p, -1, sizeof(p));
	vector <pair<pair<int, int>, int>> adj;
	int P, w, c, v;
	cin >> P >> w;
	cin >> c >> v;
	for (int i = 0; i < w; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		adj.push_back({ {s,e},w });
	}
	sort(adj.begin(), adj.end(), compare);
	for (int i = 0; i < adj.size(); i++)
	{
		merge(adj[i].first.first, adj[i].first.second);
		if (find(c) == find(v))
		{
			cout << adj[i].second;
			return 0;
		}
	}
}