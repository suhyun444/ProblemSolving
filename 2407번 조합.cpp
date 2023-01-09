#include <iostream>
#include <cstring>

using namespace std;

string cache[101][101];
string Add(string a, string b)
{
	int sum = 0;
	string ret;
	while (!a.empty() || !b.empty() || sum)
	{
		if (!a.empty())
		{
			sum += a.back() -'0';
			a.pop_back();
		}
		if (!b.empty())
		{
			sum += b.back() - '0';
			b.pop_back();
		}
		int cur = sum % 10;
		ret += '0' + cur;
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
string solve(int n, int m)
{
	if (n == m || m == 0)return "1";
	string& ret = cache[n][m];
	if (ret != "")return ret;
	ret = Add(solve(n - 1, m - 1),solve(n - 1, m));
	return ret;
}
int main()
{
	int n, m;
	cin >> n >> m;
	string ans = solve(n, m);
	cout << ans;
}