#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
bool func(int mid)
{
	int count = 1;
	int curMoney = mid;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > mid)return false;
		if (curMoney < arr[i])
		{
			curMoney = mid - arr[i];
			count++;
		}
		else
		{
			curMoney -= arr[i];
		}
	}
	return count <= m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		sum += a;
		arr.push_back(a);
	}
	int lo = 0;
	int hi = sum + 1;
	int result = 0;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (func(mid))
		{
			hi = mid;
			result = mid;
		}
		else
		{
			lo = mid;
		}
	}
	cout << result;
}