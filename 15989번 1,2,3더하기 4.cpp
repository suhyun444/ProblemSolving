#include <iostream>
#include <cstring>

using namespace std;

long long cache[3][10000];

long long solve(int n, int state)
{
	if (n < 0) return 0;
	if (n == 0) return 1;

	int& res = cache[state][n];
	if (res) return res;

	for (int i = stand; i >= 1; i--)
		res += solve(num - i, i);

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 0)cout << "0\n";
		else cout << solve(n,2) << "\n";
	}
}