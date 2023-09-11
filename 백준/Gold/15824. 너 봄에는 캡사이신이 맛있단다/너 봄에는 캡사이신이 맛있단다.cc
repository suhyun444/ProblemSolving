#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long power(int a, int c)
{
	if (c == 0)return 1;
	if (c == 1)return a;
	long long x = power(a, c / 2);
	x %= 1000000007;
	if (c % 2 == 0)
	{
		return (x * x) % 1000000007;
	}
	else
	{
		return (x * x * a) % 1000000007;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	long long result = 0;
	for (int i = 0; i < n; ++i)
	{
		result += arr[i] * power(2, i);
		result -= arr[i] * power(2, n - i - 1);
		result %= 1000000007;
	}
	cout << result;
}