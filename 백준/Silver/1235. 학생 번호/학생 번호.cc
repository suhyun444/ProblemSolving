#include <iostream>
#include <vector>

using namespace std;

bool CompareSubString(int s, int n,string s1,string s2)
{
	for (int i = s; i < n; ++i)
	{
		if (s1[i] != s2[i])return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; ++i)cin >> arr[i];
	int len = arr[0].size();
	for (int i = 1; i <= len; ++i)
	{
		bool canMake = true;
		for (int j = 0; j < n-1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				if (CompareSubString(len - i, len, arr[j], arr[k]))
				{
					canMake = false;
					break;
				}
			}
			if (!canMake)break;
		}
		if (canMake)
		{
			cout << i;
			break;
		}
	}

}