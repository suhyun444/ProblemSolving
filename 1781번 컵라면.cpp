#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)return a.second > b.second;
	return a.first < b.first;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> cup;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cup.push_back({ a,b });
	}
	sort(cup.begin(), cup.end(), compare);
	priority_queue<int,vector<int>,greater<int>> result;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (cup[i].first > count)
		{
			result.push(cup[i].second);
			count++;
		}
		else
		{
			if (cup[i].second > result.top())
			{
				result.pop();
				result.push(cup[i].second);
			}
		}
	}
	int ans = 0;
	while (!result.empty())
	{
		ans += result.top();
		result.pop();
	}
	cout << ans;
}