#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> number;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			number.push_back(s);
		}
		bool isFind = false;
		sort(number.begin(), number.end());
		for (int i = 0; i < n - 1; i++)
		{
			if (number[i].size() > number[i + 1].size())continue;
			if (number[i] == number[i + 1].substr(0, number[i].size()))
			{
				isFind = true;
			}
		}
		if (!isFind)cout << "YES\n";
		else cout << "NO\n";
		number.clear();
	}
}