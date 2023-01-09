#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> backTracking;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int ans = 2e9;
int Distance(pair<int, int> a, pair<int, int> b)
{
	int x = a.first - b.first;
	if (x < 0)x *= -1;
	int y = a.second - b.second;
	if (y < 0) y *= -1;
	return x + y;
}
int GetMinimumDistance(pair<int, int> cur)
{
	int minDistance = 2e9;
	for (int i = 0; i < backTracking.size(); i++)
	{
		minDistance = min(minDistance, Distance(cur, chicken[backTracking[i]]));
	}
	return minDistance;
}
void Solve(int startIndex, int length)
{
	if (length == m)
	{
		int cur = 0;
		for (int i = 0; i < house.size(); i++)
		{
			cur += GetMinimumDistance(house[i]);
		}
		ans = min(ans, cur);
	}
	for (int i = startIndex; i < chicken.size(); i++)
	{
		backTracking.push_back(i);
		Solve(i + 1, length + 1);
		backTracking.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int item;
			cin >> item;
			if (item == 1)house.push_back({ i,j });
			else if(item == 2)chicken.push_back({ i,j });
		}
	}
	Solve(0, 0);
	cout << ans;
}
