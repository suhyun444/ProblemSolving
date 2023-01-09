#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int C, N;
int cache[21][1001];
vector<pair<int, int>> city;
int solve(int n, int c)
{
	if (c >= C)return 0;
	if (n == N)return 1e9;
	int& ret = cache[n][c];
	if (ret != -1)return ret;
	ret = 1e9;
	for (int i = 0;; i++)
	{
		if (c + city[n].second * (i - 1) <= C)
		{
			ret = min(ret, solve(n + 1, c + city[n].second * i) + city[n].first * i);
		}
		else break;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> C >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		city.push_back({ a,b });
	}
	cout << solve(0, 0);
}