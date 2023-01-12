#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Edge
{
	int s, e;
	double w;
	Edge(int _s, int _e, double _w)
	{
		s = _s;
		e = _e;
		w = _w;
	}
};
int n, m;
int p[1001];
vector<Edge> edges;
pair<long long, long long> position[1001];
bool Compare(Edge& e1, Edge& e2)
{
	return e1.w < e2.w;
}
int Find(int cur)
{
	if (p[cur] == -1)return cur;
	return p[cur] = Find(p[cur]);
}
bool Merge(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b)return false;
	p[b] = a;
	return true;
}
double CalcDist(pair<long long, long long> p1, pair<long long, long long> p2)
{
	long long powX = p1.first - p2.first;
	powX *= powX;
	long long powY = p1.second - p2.second;
	powY *= powY;
	return sqrt(powX + powY);
}
void MakeEdges()
{
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			Edge newEdge = Edge(i, j, CalcDist(position[i], position[j]));
			edges.push_back(newEdge);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(p, -1, sizeof(p));
	cin >> n >> m;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		long long x, y;
		cin >> x >> y;
		position[i] = { x,y };
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (Merge(a, b))
		{
			count++;
		}
	}
	MakeEdges();
	sort(edges.begin(), edges.end(), Compare);
	double result = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (Merge(edges[i].s, edges[i].e))
		{
			count++;
			result += edges[i].w;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << result;
}