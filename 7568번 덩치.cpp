#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		p.push_back({ x,y });
	}
	for (int i = 0; i < n; i++)
	{
		int ans = 1;
		for (int j = 0; j < n; j++)
		{
			if (p[j].first > p[i].first && p[j].second > p[i].second)
			{
				ans++;
			}
		}
		cout << ans << " ";
	}
}