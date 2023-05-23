#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int p[1001];
int n, m, k;
bool isPowerPlant[1001];
struct Edge {
	Edge(int u, int v, int w) :u{ u }, v{ v }, w{ w } {}
	int u, v, w;
};
bool Compare(const Edge& e1, const Edge& e2)
{
	return e1.w < e2.w;
}
int Find(int cur)
{
	if (p[cur] < 0)return cur;
	return p[cur] = Find(p[cur]);
}
bool Merge(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b)
	{
		if (isPowerPlant[b])p[a] = b;
		else p[b] = a;
		return true;
	}
	return false;
}
bool isEnd()
{
	for (int i = 1; i <= n; i++)
	{
		if (!isPowerPlant[Find(i)])return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(p, -1, sizeof(p));
	vector<Edge> edges;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		isPowerPlant[a] = true;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(Edge(u, v, w));
	}
	sort(edges.begin(), edges.end(), Compare);
	int result = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (isPowerPlant[Find(edges[i].u)] && isPowerPlant[Find(edges[i].v)])continue;
		if (Merge(edges[i].u,edges[i].v))
		{
			bool flag = isPowerPlant[Find(edges[i].u)] || isPowerPlant[Find(edges[i].v)];
			isPowerPlant[Find(edges[i].u)] = flag;
			isPowerPlant[Find(edges[i].v)] = flag;
			result += edges[i].w;
		}
		if (isEnd())break;
	}
	cout << result;
}