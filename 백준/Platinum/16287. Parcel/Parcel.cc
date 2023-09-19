#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int w, n;
int canMake[800000];
vector<int> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> w >> n;
	arr.resize(n);
	for (int i = 0; i < 800000; ++i)canMake[i] = 2e9;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n - 3; ++i)
	{
		for (int j = i + 1; j < n - 2; ++j)
		{
			if (arr[i] + arr[j] > w)continue;
			canMake[arr[i] + arr[j]] = min(canMake[arr[i] + arr[j]], j);
		}
	}
	for (int i = 2; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[i] + arr[j] > w)continue;
			if (canMake[w - arr[i] - arr[j]] < i)
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}