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
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), Compare);
	if (arr[0][0] == '0')
	{
		cout << "0";
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
	}
}