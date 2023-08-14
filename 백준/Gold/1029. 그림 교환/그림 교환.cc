#include <iostream>
#include <cstring>

using namespace std;

int N;
int cost[15][15];
int cache[15][10][1 << 16 - 1];
int solve(int n,int prevCost,int state)
{
	if (n == N)return 0;
	int& ret = cache[n][prevCost][state];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i < N; ++i)
	{
		if (cost[n][i] >= prevCost && (state & (1 << i)) == 0)
		{
			ret = max(ret, solve(i, cost[n][i], state | (1 << i)) + 1);
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
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char item;
			cin >> item;
			cost[i][j] = item - '0';
		}
	}
	cout << solve(0, 0, 1) + 1;
}