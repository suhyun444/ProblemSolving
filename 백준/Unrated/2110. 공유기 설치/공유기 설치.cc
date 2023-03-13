#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;
vector<int> position;
bool func(int mid)
{
	int cnt = 1;
	int curPos = position[0];
	for (int i = 1; i < n; i++)
	{
		if (position[i] - curPos >= mid)
		{
			curPos = position[i];
			cnt++;
		}
	}
	return cnt >= c;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		position.push_back(x);
	}
	sort(position.begin(), position.end());
	int lo = 0, hi = position.back() + 1;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (func(mid))
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << lo;
}