#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int cache[51];
vector<int> adj[51];
bool Compare(int a, int b)
{
	return a > b;
}
int Solve(int cur)
{
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	vector<int> cost;
	for (int next : adj[cur])
	{
		cost.push_back(Solve(next));
	}
	sort(cost.begin(), cost.end(), Compare);
	for (int i = 0; i < cost.size(); i++)
	{
		cost[i] += i + 1;
		ret = max(ret, cost[i]);
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (i == 0)continue;
		adj[a].push_back(i);
	}
	cout << Solve(0);
}