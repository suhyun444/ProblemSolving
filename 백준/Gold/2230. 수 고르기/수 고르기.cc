#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int l = 0;
	int r = 0;
	int ans = 2e9;
	while (r < n)
	{
		if(arr[r] - arr[l] >= m)
			ans = min(ans, arr[r] - arr[l]);
		if (l < r && arr[r] - arr[l + 1] >= m)
			l++;
		else
			r++;
	}
	cout << ans;
}