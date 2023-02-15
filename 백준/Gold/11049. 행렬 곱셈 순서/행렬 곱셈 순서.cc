#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<pair<int, int>> mat;
int cache[502][502];
int Solve(int l, int r)
{
	if (l == r)return 0;
	if (l + 1 == r)
	{
		return mat[l].first * mat[r].first * mat[r].second;
	}
	int& ret = cache[l][r];
	if (ret != -1)return ret;
	ret = 2147483646;
	for (int i = l; i < r; i++)
	{
		ret = min(ret, Solve(l, i) + Solve(i + 1, r) + mat[l].first * mat[i].second * mat[r].second);
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
	{
		int a, b;
		cin >> a >> b;
		mat.push_back({ a,b });
	}
	cout << Solve(0, n - 1);
}