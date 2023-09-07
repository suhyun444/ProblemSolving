#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int p[3001];
int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int ret = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	if (ret == 0)return 0;
	else if (ret < 0)return -1;
	else return 1;
}
int CheckCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int a = CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4);
	int b = CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2);
	if (a == 0 && b == 0)
	{
		if (make_pair(x1, y1) > make_pair(x2, y2))
		{
			long long temp = x1;
			x1 = x2;
			x2 = temp;
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		if (make_pair(x3, y3) > make_pair(x4, y4))
		{
			long long temp = x3;
			x3 = x4;
			x4 = temp;
			temp = y3;
			y3 = y4;
			y4 = temp;
		}
		if (make_pair(x1, y1) <= make_pair(x4, y4) && make_pair(x3, y3) <= make_pair(x2, y2))
			return 1;
		else
			return 0;
	}
	else
	{
		if (a <= 0 && b <= 0)
			return 1;
		else
			return 0;
	}
}
int Find(int cur)
{
	if (p[cur] < 0)return cur;
	return p[cur] = Find(p[cur]);
}
bool Merge(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b)return false;
	p[a] += p[b];
	p[b] = a;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(p, -1, sizeof(p));
	int n;
	cin >> n;
	vector< pair<pair<int, int>, pair<int, int>>> arr;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr.push_back({ {a,b},{c,d} });
	}
	int result = n;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (CheckCross(arr[i].first.first, arr[i].first.second, arr[i].second.first, arr[i].second.second,
				arr[j].first.first, arr[j].first.second, arr[j].second.first, arr[j].second.second))
			{
				if (Merge(i, j))
				{
					--result;
				}
			}
		}
	}
	int maxSize = 0;
	for (int i = 0; i < n; ++i)
		maxSize = max(maxSize, -p[i]);
	cout << result << "\n" << maxSize;
}