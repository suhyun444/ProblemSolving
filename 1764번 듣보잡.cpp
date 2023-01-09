#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<string, int> map;
	int n, m;
	cin >> n >> m;
	string s;
	int num = 0;
	vector<string> ans;
	for (int i = 0; i < n + m; i++)
	{
		cin >> s;
		if (map.find(s) == map.end())
		{
			map.insert({ s,1 });
		}
		else
		{
			num++;
			map[s]++;
			ans.push_back(s);
		}
	}
	cout << num << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]<<"\n"
	}
}