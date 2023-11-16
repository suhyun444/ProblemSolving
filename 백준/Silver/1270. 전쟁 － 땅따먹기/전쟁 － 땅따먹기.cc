#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<long long, int> m;
	int t;
	cin >> t;
	while (t--)
	{
		m.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			long long a;
			cin >> a;
			if (m.find(a) != m.end())
				m[a]++;
			else
				m.insert({ a,1 });
		}
		long long maxNum = 0;
		int maxCount = 0;
		for (auto& elem : m)
		{
			if (elem.second > maxCount)
			{
				maxNum = elem.first;
				maxCount = elem.second;
			}
		}
		if (maxCount > n / 2)
			cout << maxNum << "\n";
		else
			cout << "SYJKGW\n";
	}
}
