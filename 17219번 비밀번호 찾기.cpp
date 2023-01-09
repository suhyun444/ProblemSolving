#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<string, string> map;
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string link, pw;
		cin >> link >> pw;
		map.insert({ link,pw });
	}
	for (int i = 0; i < m; i++)
	{
		string link;
		cin >> link;
		cout << map[link] << "\n";
	}
}