#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cow;
	multiset<int> ms;
	int c, n;
	cin >> c >> n;
	vector<int> chicken(c);
	for (int i = 0; i < c; ++i)
		cin >> chicken[i];
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		cow.push({ a,b });
	}
	sort(chicken.begin(), chicken.end());
	int result = 0;
	for (int i = 0; i < c; ++i)
	{
		while (!cow.empty() && chicken[i] >= cow.top().first)
		{
			ms.insert(cow.top().second);
			cow.pop();
		}
		while (!ms.empty())
		{
			int front = *ms.begin();
			ms.erase(ms.begin());
			if (front >= chicken[i])
			{
				result++;
				break;
			}
		}
	}
	cout << result;
}