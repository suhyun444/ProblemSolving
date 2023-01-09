#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> arr;
int cache[1001][1001];
int solve(int stat,int s, int e)
{
	if (s > e)return 0;
	int& ret = cache[s][e];
	if (ret != -1)return ret;
	if (stat == 0)
		ret = max(solve(1, s + 1, e) + arr[s], solve(1, s, e - 1) + arr[e]);
	else
		ret = min(solve(0, s + 1, e), solve(0, s, e - 1));
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			arr.push_back(a);
		}
		cout << solve(0,0, n - 1) << "\n";
		arr.clear();
	}
}