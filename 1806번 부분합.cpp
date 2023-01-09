#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int ans = 2e9;
	vector<int> arr;
	int n, s;
	cin >> n >> s;
	arr.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
		arr[i] += arr[i - 1];
	}
	int l = 0, r = 0;
	while (true)
	{
		if (arr[r] - arr[l] < s && r < n)
		{
			r++;
		}
		else if (arr[r] - arr[l] >= s)
		{
			ans = min(ans, r - l);
			l++;
		}
		else if (arr[r] - arr[l] < s && r == n)
			break;
	}
	if (ans == 2e9)cout << "0";
	else cout << ans;
}