#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<pair<int, int>> consulting;
int cache[1500001];
int solve(int day)
{
	if (day == n)return 0;
	int& ret = cache[day];
	if (ret != -1)return ret;
	ret = solve(day + 1);
	if (day + consulting[day].first <= n)
		ret = max(ret, solve(day + consulting[day].first) + consulting[day].second);
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
		int t, p;
		cin >> t >> p;
		consulting.push_back({ t,p });
	}
	cout << solve(0);
}