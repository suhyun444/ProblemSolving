#include <iostream>
#include <cstring>
#define MOD 1000000003

using namespace std;

int N, K;
int cache[2][1001][1001];
int solve(int state,int n,int k)
{
	if (k == K)return 1;
	int& ret = cache[state][n][k];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = n + 2; i < N- K + k + 1; i++)
	{
		if (state == 1 && i == N - 1)continue;
		ret += solve(state, i, k + 1) % MOD;
		ret %= MOD;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> N >> K;
	int result = solve(1, 0, 1) % MOD;
	for (int i = 1; i < N - K + 1; i++)
	{
		result += solve(0, i, 1) % MOD;
		result %= MOD;
	}
	cout << result;
}