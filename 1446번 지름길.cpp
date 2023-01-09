#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, d;
int cache[10001];
vector < pair<pair<int, int>,int>> loads;

int solve(int x)
{
	if (x == d)return 0;
	if (x > d)return 1e9;
	int& ret = cache[x];
	if (ret != -1)return ret;
	
	ret = d - x;
	for (int i = 0; i < loads.size(); i++)
	{
		if (loads[i].first.first >= x)
		{
			ret = min(ret, solve(loads[i].first.second) + loads[i].second + loads[i].first.first - x);
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(cache, -1, sizeof(cache));
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (b - a > c)
		{
			loads.push_back({ {a,b},c });
		}
	}
	cout << solve(0);
}
