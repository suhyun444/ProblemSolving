#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(const string& s1, const string& s2)
{
	return s1 + s2 > s2 + s1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<string> nums;
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; ++i)
	{
		string s;
		cin >> s;
		nums.push_back(s);
	}
	int maxCount = 0;
	sort(nums.begin(), nums.end(), Compare);
	for (int i = 0; i < k; ++i)
	{
		maxCount = max(maxCount, (int)nums[i].size());
	}
	bool isPrinted = false;
	for (int i = 0; i < min(k, n); ++i)
	{
		if (nums[i].size() == maxCount && !isPrinted)
		{
			for (int j = k; j < n; ++j)
				cout << nums[i];
			isPrinted = true;
		}
		cout << nums[i];
	}
}