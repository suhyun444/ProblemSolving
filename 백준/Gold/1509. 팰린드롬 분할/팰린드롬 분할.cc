#include <iostream>
#include <cstring>

using namespace std;

string s;
int cache[2501][2501];
int solve(int start, int n,bool canMake)
{
	if (n == s.size())
	{
		if (!canMake)return 2e9;
		return 0;
	}
	int& ret = cache[start][n];
	if (ret != -1)return ret;
	ret = 2e9;
	int l = start, r = n;
	bool isPelindrome = true;
	while (l < r)
	{
		if (s[l] != s[r])
		{
			isPelindrome = false;
			break;
		}
		++l;
		--r;
	}
	if (isPelindrome)
	{
		ret = min(ret, solve(n + 1, n + 1, true) + 1);
	}
	ret = min(ret, solve(start, n + 1,false));
	return ret;
}
int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> s;
	cout << solve(0, 0,true);
}