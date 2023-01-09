#include <iostream>
#include <cstring>

using namespace std;

int scv[3];
int cache[61][61][61];

int solve(int a,int b,int c)
{
	int deadCount = 0;
	if (a <= 0) {
		a = 0;
		deadCount++;
	}
	if (b <= 0)
	{
		b = 0;
		deadCount++;
	}
	if (c <= 0)
	{
		c = 0;
		deadCount++;
	}
	if (a == 0 && b == 0 && c == 0)return 0;
	int& ret = cache[a][b][c];
	if (ret != -1)return ret;
	ret = 1e9;
	if (deadCount == 2)
	{
		ret = min(ret, min(solve(a - 9, b, c) + 1, min(solve(a, b - 9, c) + 1, solve(a, b, c - 9) + 1)));
	}
	else
	{
		ret = min(ret, min(solve(a - 9, b - 3, c - 1) + 1, solve(a - 9, b - 1, c - 3) + 1));
		ret = min(ret, min(solve(a - 3, b - 9, c - 1) + 1, solve(a - 1, b - 9, c - 3) + 1));
		ret = min(ret, min(solve(a - 3, b - 1, c - 9) + 1, solve(a - 1, b - 3, c - 9) + 1));
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> scv[i];
	cout << solve(scv[0], scv[1], scv[2]);
}