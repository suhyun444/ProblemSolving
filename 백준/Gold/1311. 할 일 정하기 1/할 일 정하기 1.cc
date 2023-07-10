#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int cache[20][1 << 20];
vector<pair<int,int>> work[20];
int solve(int n,int people)
{
	if (n == N)return 0;
	int& ret = cache[n][people];
	if (ret != -1)return ret;
	ret = 2e9;
	if (work[n].size() == 0)
	{
		ret = solve(n + 1, people);
	}
	else
	{
		for (int i = 0; i < work[n].size(); i++)
		{
			if (((people >> work[n][i].first) & 1) == 0)
			{
				ret = min(ret, solve(n + 1, people | (1 << work[n][i].first)) + work[n][i].second);
			}
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
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int d;
			cin >> d;
			work[j].push_back({ i,d });
		}
	}
	cout << solve(0, 0);
}