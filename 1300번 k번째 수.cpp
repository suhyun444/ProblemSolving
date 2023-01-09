#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n, s;
	cin >> n >> s;

	long long lo = 1;
	long long hi = s;
	while (lo < hi)
	{
		long long mid = (lo + hi) / 2;
		long long cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += min(mid / i, n);
		}
		if (cnt < s)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid;
		}
	}
	cout << lo;
}