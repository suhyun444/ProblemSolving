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
	vector<int> arr(n);
	vector<int> lis;
	vector<int> tracking;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		if (lis.empty() || lis.back() < arr[i])
		{
			lis.push_back(arr[i]);
			tracking.push_back(lis.size() - 1);
		}
		else
		{
			int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[index] = arr[i];
			tracking.push_back(index);
		}
	}
	cout << lis.size() << "\n";
	int index = lis.size() - 1;
	vector<int> ans;
	for (int i = tracking.size() - 1; i >= 0; --i)
	{
		if (index == tracking[i])
		{
			index--;
			ans.push_back(arr[i]);
		}
	}
	for (int i = ans.size() - 1; i >= 0; --i)
	{
		cout << ans[i] << " ";
	}
}