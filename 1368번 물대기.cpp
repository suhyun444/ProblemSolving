#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> edge;
int p[301];
int find(int cur)
{
	if (p[cur] < 0)return cur;
	return p[cur] = find(p[cur]);
}
bool merge(int a,int b)
{
	a = find(a);
	b = find(b);
	if (a == b)return false;
	p[b] = a;
	return true;
}
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		edge.push_back({{0, i}, c});
	}
	for (int i = 0; i <= n; i++)p[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int p;
			cin >> p;
			edge.push_back({ { i,j},p });
		}
	}
	sort(edge.begin(), edge.end(), compare);
	int count = 0;
	int result = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		if (merge(edge[i].first.first, edge[i].first.second))
		{
			result += edge[i].second;
			if (++count == n)
			{
				cout << result;
				return 0;
			}
		}
	}
}