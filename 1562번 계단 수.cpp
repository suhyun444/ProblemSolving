#include <iostream>
#include <cstring>
#define MOD 1000000000;

using namespace std;

int N;
long long cache[101][10][(1<<10) + 1];
long long solve(int n, int number,int visit)
{
	if (n == N)
	{
		if (number == 0)return 0;
		if (visit == (1 << 10) - 1)
			return 1;
		else return 0;
	}
	long long& ret = cache[n][number][visit];
	if (ret != -1)return ret;
	ret = 0;
	if (number + 1 <= 9)
		ret += solve(n + 1, number + 1, visit | (1 << (number + 1))) % MOD;
	if (number - 1 >= 0)
		ret += solve(n + 1, number - 1, visit | (1 << (number - 1))) % MOD;
	ret %= MOD;
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans += solve(1, i, (1 << i));
		ans %= MOD;
	}
	cout << ans;
}