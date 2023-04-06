#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> arr;
bool func(int mid)
{
	int curPos = arr[0];
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - curPos >= mid)
		{
			curPos = arr[i];
			count++;
		}
	}
	return count >= c;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int maxDistance = 0;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	int lo = 0;
	int hi = arr.back() + 1;
	int result = 0;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (func(mid))
		{
			lo = mid;
			result = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << result;
}