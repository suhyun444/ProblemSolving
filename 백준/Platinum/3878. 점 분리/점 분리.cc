#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
	int x, y;
	Point(int x, int y) :x{ x }, y{ y } {}
	Point() :x{ 0 }, y{ 0 } {}
	bool operator<(const Point& o)
	{
		if (x == o.x)return y < o.y;
		return x < o.x;
	}
};
Point mainPoint;
bool Compare(const Point& p1, const Point& p2)
{
	if (p1.y == p2.y)return p1.x < p2.x;
	return p1.y < p2.y;
}
long long CCW(const Point& p1, const Point& p2, const Point& p3)
{
	return 1LL * (p2.x - p1.x) * (p3.y - p1.y) - 1LL * (p3.x - p1.x) * (p2.y - p1.y);
}
bool CompareAngle(const Point& p1, const Point& p2)
{
	long long ccw = CCW(mainPoint, p1, p2);
	if (ccw)
		return ccw > 0;
	if (p1.y == p2.y)return p1.x < p2.x;
	return p1.y < p2.y;
}
bool CheckCross(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{
	long long a = CCW(p1,p2,p3) * CCW(p1,p2,p4);
	long long b = CCW(p3,p4,p1) * CCW(p3,p4,p2);
	int x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y, x3 = p3.x, y3 = p3.y, x4 = p4.x, y4 = p4.y;
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
			return true;
		else
			return false;
	}
	else
	{
		if (a <= 0 && b <= 0)
			return true;
		else
			return false;
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<Point> bp;
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			bp.push_back(Point(a, b));
		}
		sort(bp.begin(), bp.end(), Compare);
		mainPoint = bp[0];
		sort(bp.begin() + 1, bp.end(), CompareAngle);
		vector<int> bv;
		bv.push_back(0);
		if(n > 1)
			bv.push_back(1);
		for (int i = 2; i < n; ++i)
		{
			while (bv.size() >= 2)
			{
				int p1 = bv.back();
				bv.pop_back();
				int p2 = bv.back();
				if (CCW(bp[p2], bp[p1], bp[i]) > 0)
				{
					bv.push_back(p1);
					break;
				}
			}
			bv.push_back(i);
		}
		vector<Point> wp;
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			wp.push_back(Point(a, b));
		}
		sort(wp.begin(), wp.end(), Compare);
		mainPoint = wp[0];
		sort(wp.begin() + 1, wp.end(), CompareAngle);
		vector<int> wv;
		wv.push_back(0);
		if(m > 1)
			wv.push_back(1);
		for (int i = 2; i < m; ++i)
		{
			while (wv.size() >= 2)
			{
				int p1 = wv.back();
				wv.pop_back();
				int p2 = wv.back();
				if (CCW(wp[p2], wp[p1], wp[i]) > 0)
				{
					wv.push_back(p1);
					break;
				}
			}
			wv.push_back(i);
		}
		bool overlapped = false;
		if (wv.size() >= 3)
		{
			for (int i = 0; i < bv.size(); ++i)
			{
				bool pointFlag = true;
				for (int j = 0; j < wv.size(); ++j)
				{
					if (CCW(wp[wv[j]], wp[wv[(j + 1) % wv.size()]], bp[bv[i]]) <= 0)
					{
						pointFlag = false;
						break;
					}
				}
				if (pointFlag)
				{
					overlapped = true;
					break;
				}
			}
		}
		if (bv.size() >= 3)
		{
			for (int i = 0; i < wv.size(); ++i)
			{
				bool pointFlag = true;
				for (int j = 0; j < bv.size(); ++j)
				{
					if (CCW(bp[bv[j]], bp[bv[(j + 1) % bv.size()]], wp[wv[i]]) <= 0)
					{
						pointFlag = false;
						break;
					}
				}
				if (pointFlag)
				{
					overlapped = true;
					break;
				}
			}
		}
		if (overlapped)
		{
			cout << "NO\n";
			continue;
		}
		if (wv.size() >= 2 && bv.size() >= 2)
		{
			for (int i = 0; i < wv.size(); ++i)
			{
				for (int j = 0; j < bv.size(); ++j)
				{
					if (CheckCross(wp[wv[i]], wp[wv[(i + 1) % wv.size()]], bp[bv[j]], bp[bv[(j + 1) % bv.size()]]))
					{
						overlapped = true;
						break;
					}
				}
				if (overlapped)	break;
			}
		}
		else if (wv.size() == 1 && bv.size() == 2)
		{
			if (CCW(wp[wv[0]], bp[bv[0]], bp[bv[1]]) == 0)
			{
				if (bp[bv[0]] < wp[wv[0]] && wp[wv[0]] < bp[bv[1]])
				{
					overlapped = true;
				}
			}
		}
		else if (bv.size() == 1 && wv.size() == 2)
		{
			if (CCW(bp[bv[0]], wp[wv[0]], wp[wv[1]]) == 0)
			{
				if (wp[wv[0]] < bp[bv[0]] && bp[bv[0]] < wp[wv[1]])
				{
					overlapped = true;
				}
			}
		}
		if (overlapped)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
}