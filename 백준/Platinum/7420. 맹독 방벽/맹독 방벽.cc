#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point
{
	int x, y;
	Point(int x, int y) :x{ x }, y{ y } {  }
	Point operator-(const Point& o)
	{
		return Point(x - o.x, y - o.y);
	}
};
vector<Point> p;
float Dot(const Point& p1, const Point& p2)
{
	return p1.x* p2.x + p1.y * p2.y;
}
bool Compare(const Point& p1,const Point& p2)
{
	if (p1.y == p2.y)return p1.x < p2.x;
	return p1.y < p2.y;
}
long long CCW(const Point& p1, const Point& p2, const Point& p3)
{
	return 1LL * (p2.x - p1.x) * (p3.y - p1.y) - 1LL * (p3.x- p1.x) * (p2.y- p1.y);
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
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		p.push_back(Point(a,b));
	}
	sort(p.begin(), p.end(), Compare);
	sort(p.begin() + 1, p.end(), CompareAngle);
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	for (int i = 2; i < n; ++i)
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
	double result = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		result += Dist(p[v[i]], p[v[(i + 1) % v.size()]]);
	}
	cout << round(result + 2 * 3.1415926535 * l);
}