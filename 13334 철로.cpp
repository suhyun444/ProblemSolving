#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


vector < pair<int, int>> people;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)swap(a, b);
		people.push_back({ b,a });
	}
	int d;
	cin >> d;
	sort(people.begin(), people.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int s = people[i].second;
		int e = people[i].first;
		if (e - s > d)continue;
		pq.push(s);
		while (!pq.empty())
		{
			if (pq.top() + d >= e)
				break;
			pq.pop();
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
}