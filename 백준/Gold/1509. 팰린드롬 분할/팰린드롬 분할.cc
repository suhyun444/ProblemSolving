#include <iostream>
#include <cstring>

using namespace std;

string s;
int cache[2501][2501];
bool isPelindrome[2501][2501];
void MakePelindromeArray()
{
	for (int i = 0; i < s.size() - 1; ++i)
	{
		isPelindrome[i][i] = true;
		if (s[i] == s[i + 1])isPelindrome[i][i + 1] = true;
	}
	isPelindrome[s.size() - 1][s.size() - 1] = true;
	for (int length = 3; length <= s.size(); ++length)
	{
		for (int l = 0; l + length - 1 < s.size(); ++l)
		{
			int r = l + length - 1;
			if (s[l] == s[r] && isPelindrome[l + 1][r - 1])isPelindrome[l][r] = true;
		}
	}
}
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
	if (isPelindrome[start][n])
		ret = min(ret, solve(n + 1, n + 1, true) + 1);
	ret = min(ret, solve(start, n + 1,false));
	return ret;
}
int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> s;
	MakePelindromeArray();
	cout << solve(0, 0,true);
}