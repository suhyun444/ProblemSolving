#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
vector<int> arr;
int cache[1000001];
int solve(int startIndex)
{
	int& ret = cache[startIndex + 1];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = startIndex + 1; i < n; i++)
	{
		if (startIndex == -1 || arr[startIndex] < arr[i])
		{
			ret = max(ret, solve(i) + 1);
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	cout << solve(-1);
}