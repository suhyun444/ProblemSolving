#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> arr;
	int n, m;
	cin >> n >> m;
	int minSet = 2e9, minSingle = 2e9;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		minSet = min(minSet, a);
		minSingle = min(minSingle, b);
	}
	int result = 0;
	if (minSet < minSingle * 6)
	{
		while (n >= 6)
		{
			result += minSet;
			n -= 6;
		}
		result += min(minSingle * n, minSet);
	}
	else
		result += minSingle * n;
	cout << result;
}