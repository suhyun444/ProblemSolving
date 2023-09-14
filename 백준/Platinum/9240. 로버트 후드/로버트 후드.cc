#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
	int x, y;
	Point(int x, int y) :x{ x }, y{ y } {}
};
vector<Point> p;
bool Compare(const Point& p1, const Point& p2)
{
	if (p1.y == p2.y) return p1.x < p2.x;
	return p1.y < p2.y;
}
long long CCW(const Point& p1, const Point& p2, const Point& p3)
{
	return 1LL * (p2.x - p1.x) * (p3.y - p1.y) - 1LL * (p3.x - p1.x) * (p2.y - p1.y);
}
double Dist(const Point& p1, const Point& p2)
{
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
bool CompareAngle(const Point& p1, const Point& p2)
{
	long long ccw = CCW(p[0], p1, p2);
	if (ccw)
		return ccw > 0;
	if (p1.y == p2.y)return p1.x < p2.x;
	return p1.y < p2.y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		int a, b;
		cin >> a >> b;
		p.push_back(Point(a, b));
	}
	sort(p.begin(), p.end(), Compare);
	sort(p.begin() + 1, p.end(), CompareAngle);
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	for (int i = 2; i < c; ++i)
	{
		while (v.size() >= 2)
		{
			int p1 = v.back();
			v.pop_back();
			int p2 = v.back();
			if (CCW(p[p2], p[p1], p[i]) > 0)
			{
				v.push_back(p1);
				break;
			}
		}
		v.push_back(i);
	}
	double maxDistance = 0;
	for (int i = 0; i < v.size() - 1; ++i)
	{
		for (int j = i + 1; j < v.size(); ++j)
		{
			maxDistance = max(maxDistance, Dist(p[v[i]], p[v[j]]));
		}
	}
	cout << fixed;
	cout.precision(6);
	cout << maxDistance;
}
