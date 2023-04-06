#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<long long> arr;
bool func(long long mid)
{
	long long count = 0;
	for (int i = 0; i < k; i++)
	{
		count += arr[i] / (mid );
	}
	return count >= n;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long maxLength = 0;
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		long long a;
		cin >> a;
		maxLength = max(maxLength, a);
		arr.push_back(a);
	}
	long long lo = 0;
	long long hi = maxLength + 1;
	long long result = 0;
	while (lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2;
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