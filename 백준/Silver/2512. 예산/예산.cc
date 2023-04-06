#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
bool func(int mid)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += min(mid, arr[i]);
	}
	return sum <= m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int maxCost = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		maxCost = max(maxCost, a);
		arr.push_back(a);
	}
	cin >> m;
	int lo = 0;
	int hi = maxCost + 1;
	int result = 0;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (func(mid))
		{
			lo = mid;
			result = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << result;
} 