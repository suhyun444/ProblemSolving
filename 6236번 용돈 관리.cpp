#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
int func(int mid)
{
	int count = 1;
	int curMoney = mid;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > mid)return 2e9;
		if (arr[i] > curMoney)
		{
			curMoney = mid;
			curMoney -= arr[i];
			count++;
		}
		else
		{
			curMoney -= arr[i];
		}
	}
	return count;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		arr.push_back(item);
	}
	int lo = 0;
	int hi = 1e9;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (func(mid) > m)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << hi;
}