#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> line;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		line.push_back({ a,b });
	}
	sort(line.begin(), line.end());
	vector<pair<int, int>> tracking;
	vector<int> lis;
	for (int i = 0; i < n; i++)
	{
		if (lis.empty() || lis.back() < line[i].second)
		{
			tracking.push_back({ lis.size(),line[i].first });
			lis.push_back(line[i].second);
		}
		else
		{
			int index = lower_bound(lis.begin(),lis.end(),line[i].second) - lis.begin();
			lis[index] = line[i].second;
			tracking.push_back({ index ,line[i].first });
		}
	}
	vector<int> result;
	int index = lis.size() - 1;
	for (int i = tracking.size() - 1; i >= 0; i--)
	{
		if (index == tracking[i].first)
		{
			index--;
		}
		else
		{
			result.push_back(tracking[i].second);
		}
	}
	cout << result.size() << "\n";
	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i] << "\n";
	}
}