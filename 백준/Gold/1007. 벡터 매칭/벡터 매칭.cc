#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<pair<long long, long long>> points;
vector<int> back;
bool visited[21];
double Calculate(int n)
{
	double result = 0;
	long long x1 = 0;
	long long x2 = 0;
	long long y1 = 0;
	long long y2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
		{
			x1 += points[i].first;
			y1 += points[i].second;
		}
		else
		{
			x2 += points[i].first;
			y2 += points[i].second;
		}
	}
	long long x = x1 - x2;
	long long y = y1 - y2;
	long long powX = pow(x, 2);
	long long powY = pow(y, 2);
	result = sqrt(powX + powY);
	return result;
}
double BackTracking(int startIndex,int length, int n)
{
	if (length == n / 2)
	{
		return Calculate(n);
	}
	double result = 2e9;
	for (int i = startIndex; i < n; i++)
	{
		visited[i] = true;
		result = min(result, BackTracking(i + 1,length + 1, n));
		visited[i] = false;
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(6);
	cout << fixed;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			points.push_back({ x,y });
		}
		cout << BackTracking(0,0, n) << "\n";
		points.clear();
	}
}