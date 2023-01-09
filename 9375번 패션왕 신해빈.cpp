#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		map<string, int> typeToIndex;
		int ans = 1;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			if (typeToIndex.find(b) == typeToIndex.end())
			{
				typeToIndex.insert({ b,1});
			}
			else
			{
				typeToIndex[b]++;
			}
		}
		for (pair<string, int> cur : typeToIndex)
		{
			ans *= (cur.second + 1);
		}
		ans -= 1;
		cout << ans << "\n";
	}
}