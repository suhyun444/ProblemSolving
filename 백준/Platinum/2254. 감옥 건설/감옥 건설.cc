#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Point
{
	int x, y;
	bool used = false;
	Point(int x, int y) :x{ x }, y{ y }, used{ false } {}
};
int px, py;
vector <Point>p;
bool Compare(const Point& p1, const Point& p2)
{
	if ((p1.used && p2.used) || (!p1.used && !p2.used))
	{
		if (p1.y == p2.y)return p1.x < p2.x;
		return p1.y < p2.y;
	}
	else if (p1.used && !p2.used)return false;
	return true;
}
long long CCW(const Point& p1, const Point& p2, const Point& p3)
{
	return 1LL * (p2.x - p1.x) * (p3.y - p1.y) - 1LL * (p3.x - p1.x) * (p2.y - p1.y);
}
bool CompareAngle(const Point& p1, const Point& p2)
{
	long long res = CCW(p[0], p1, p2);
	if (res == 0) {
		if (p1.y - p[0].y == p2.y - p[0].y) return p1.x - p[0].x < p2.x - p[0].x;
		else return p1.y - p[0].y < p2.y - p[0].y;
	}
	else {
		return res > 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n >> px >> py;
	Point center = Point(px, py);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		p.push_back(Point(a, b));
	}
	int result = 0;
	while (n >= 3)
	{
		sort(p.begin(), p.end(), Compare);
		sort(p.begin() + 1, p.begin() + n, CompareAngle);
		vector<int> s;
		s.push_back(0);
		p[0].used = true;
		s.push_back(1);
		p[1].used = true;
		for (int i = 2; i < n; ++i)
		{
			while (s.size() >= 2)
			{
				int p1 = s.back();
				p[p1].used = false;
				s.pop_back();
				int p2 = s.back();
				if (CCW(p[p2], p[p1], p[i]) > 0)
				{
					s.push_back(p1);
					p[p1].used = true;
					break;
				}
			}
			s.push_back(i);
			p[i].used = true;
		}
		bool canMake = true;
		for (int i = 0; i < s.size() - 1; ++i)
		{
			if (CCW(p[s[i]], p[s[i + 1]], center) <= 0)
			{
				canMake = false;
				break;
			}
		}
		if (!canMake)break;
		result++;
		n -= s.size();
	}
	cout << result;
}