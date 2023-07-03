#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w) :u{ u }, v{ v }, w{ w } {}
};
bool Compare(const Edge& e1, const Edge& e2)
{
	return e1.w < e2.w;
}
vector<Edge> edges;
int p[100001];
int find(int cur)
{
	if (p[cur] < 0)return cur;
	return p[cur] = find(p[cur]);
}
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		p[b] = a;
		return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(p, -1, sizeof(p));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(Edge(a, b, c));
	}
	if (n == 2)
	{
		cout << "0";
		return 0;
	}
	sort(edges.begin(), edges.end(), Compare);
	int count = 0, result = 0;
	for (int i = 0; i < m; i++)
	{
		if (merge(edges[i].u, edges[i].v))
		{
			result += edges[i].w;
			count++;
			if (count == n - 2)
				break;
		}
	}
	cout << result;
}