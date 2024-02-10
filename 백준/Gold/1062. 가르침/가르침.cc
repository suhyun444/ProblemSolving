#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<string> arr;
bool known[26];
int check()
{
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		bool canRead = true;
		for (int j = 4; j < arr[i].size() - 4; ++j)
		{
			if (!known[arr[i][j] - 'a'])
			{
				canRead = false;
				break;
			}
		}
		if (canRead)result++;
	}
	return result;
}
int Backtracking(int cur, int size)
{
	if (size == m - 5)
	{
		return check();
	}
	int ret = 0;
	for (int i = cur; i < 26; ++i)
	{
		if (i == 0 || i == ('n' - 'a') || i == ('t' - 'a') || i == ('i' - 'a') || i == ('c' - 'a'))
			continue;
		known[i] = true;
		ret = max(ret,Backtracking(i + 1, size + 1));
		known[i] = false;
	}
	return ret;
}
int main()
{
	known['a' - 'a'] = true;
	known['n' - 'a'] = true;
	known['t' - 'a'] = true;
	known['i' - 'a'] = true;
	known['c' - 'a'] = true;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string item;
		cin >> item;
		arr.push_back(item);
	}
	if (m < 5)
	{
		cout << "0";
		return 0;
	}
	cout << Backtracking(0, 0);
}