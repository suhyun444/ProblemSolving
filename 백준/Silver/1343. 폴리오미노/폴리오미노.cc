#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	vector<int> arr;
	int cur = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '.')
		{
			arr.push_back(cur);
			cur = 0;
		}
		else
			++cur;
	}
	arr.push_back(cur);
	for (int i = 0;i< arr.size(); ++i)
	{
		if (arr[i] % 2 != 0)
		{
			cout << "-1";
			return 0;
		}
	}
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr[i] / 4; ++j)
		{
			cout << "AAAA";
		}
		arr[i] %= 4;
		for (int j = 0; j < arr[i] / 2; ++j)
		{
			cout << "BB";
		}
		if (i != arr.size()-1)cout << ".";
	}
}