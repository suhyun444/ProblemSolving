#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<pair<int, int>> hole;
bool visited[50001];

int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		int y, x;
		cin >> x >> y;
		hole.push_back({ y,x });
	}
	sort(hole.begin(), hole.end());
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{0,0} });
	int level = 0;

	while (!q.empty())
	{
		int size = q.size();
		pair<pair<int, int>, pair<int, int>> cur = q.front();
		q.pop();
		if (cur.first.first == t)
		{
			cout << cur.second.second;
			return 0;
		}
		for (int i = cur.second.first; i < n; i++)
		{
			if (abs(hole[i].first - cur.first.first) <= 2 && abs(hole[i].second - cur.first.second) <= 2 && !visited[i])
			{
				q.push({ {hole[i].first,hole[i].second},{i,cur.second.second + 1} });
				visited[i] = true;
			}
			else if (abs(hole[i].first - cur.first.first) > 2 && abs(hole[i].second - cur.first.second) > 2)
				break;
		}
		for (int i = cur.second.first; i >= 0; i--)
		{
			if (abs(hole[i].first - cur.first.first) <= 2 && abs(hole[i].second - cur.first.second) <= 2 && !visited[i])
			{
				q.push({ {hole[i].first,hole[i].second},{i,cur.second.second + 1} });
				visited[i] = true;
			}
			else if (abs(hole[i].first - cur.first.first) > 2 && abs(hole[i].second - cur.first.second) > 2)
				break;
		}
	}
	cout << "-1";
}
