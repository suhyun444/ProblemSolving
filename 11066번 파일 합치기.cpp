#include <iostream>
#include <cstring>

using namespace std;

int cache[501][501];
int sum[501];
int solve(int lo, int hi)
{
	if (lo == hi)return 0;
	if (lo + 1 == hi)
		return sum[hi] - sum[lo - 1];

	int& ret = cache[lo][hi];
	if (ret != -1) return ret;

	ret = 2e9;
	for (int i = lo; i < hi; i++)
	{
		int left = solve(lo, i);
		int right = solve(i + 1, hi);
		ret = min(ret, left + right);
	}
	return ret += sum[hi] - sum[lo - 1];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> sum[i];
			sum[i] += sum[i - 1];
		}
		memset(cache, -1, sizeof(cache));
		cout << solve(1, k) << "\n";
	}
}