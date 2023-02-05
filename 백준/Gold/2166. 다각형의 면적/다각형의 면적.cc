#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double CCW(double x1, double y1, double x2, double y2, double x3, double y3)
{
	return (x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1)) / 2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(1);
	cout << fixed;
	vector<pair<double, double>> points;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		points.push_back({ x, y });
	}
	double area = 0;
	for (int i = 1; i < n - 1; i++)
		area += CCW(points[0].first, points[0].second, points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);

	cout << abs(area);
}