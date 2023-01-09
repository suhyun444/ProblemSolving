#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[100001];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[n - i - 1];
	}
	int res = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			res++;
		}
	}
	cout << res;
} 