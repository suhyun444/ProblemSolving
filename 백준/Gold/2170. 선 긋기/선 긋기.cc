#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	int l = arr[0].first, r = arr[0].second;
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i].first <= r && arr[i].second > r)
		{
			r = arr[i].second;
		}
		else if (arr[i].first > r)
		{
			result += r - l;
			l = arr[i].first;
			r = arr[i].second;
		}
	}
	result += r - l;
	cout << result;
}