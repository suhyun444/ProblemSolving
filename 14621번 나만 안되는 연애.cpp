#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
char node[1001];
int p[1001];
vector<pair<pair<int,int> ,int>> edge;
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	return a.second < b.second;
}
int find(int cur)
{
	if (p[cur] < 0)return cur;
	return p[cur] = find(p[cur]);
}
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)return false;
	p[b] = a;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> node[i];
	for (int j = 0;j < m; j++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ {a,b},c });
	}
	memset(p, -1, sizeof(p));
	int count = 0;
	int result = 0;
	sort(edge.begin(), edge.end(), compare);
	for (int i = 0; i < edge.size(); i++)
	{
		if (node[edge[i].first.first] != node[edge[i].first.second])
		{
			if (merge(edge[i].first.first, edge[i].first.second))
			{
				result += edge[i].second;
				if (++count == n - 1)
				{
					cout << result;
					return 0;
				}
			}
		}
	}
	cout << "-1";
}