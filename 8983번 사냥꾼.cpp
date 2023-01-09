#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> hunter;
	int m, n, l;
	cin >> m >> n >> l;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		hunter.push_back(a);
	}
	int ans = 0;
	sort(hunter.begin(), hunter.end());
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if (y > l)continue;
		int lo = 0;
		int hi = hunter.size() - 1;
		int left = x + y - l;
		int right = x - y + l;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (left <= hunter[mid] && hunter[mid] <= right)
			{
				ans++;
				break;
			}
			else if (hunter[mid] < left)
			{
				lo = mid + 1;
			}
			else if(right < hunter[mid])
			{
				hi = mid - 1;
			}
		}
	}
	cout << ans;
}