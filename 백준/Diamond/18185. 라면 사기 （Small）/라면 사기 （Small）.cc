#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int result = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		if (arr[i + 1] > arr[i + 2])
		{
			int diff = arr[i + 1] - arr[i + 2];
			int second = min(arr[i], diff);
			arr[i] -= second;
			arr[i + 1] -= second;
			result += 5 * second;
		}
		int first = min(arr[i], min(arr[i + 1], arr[i + 2]));
		arr[i] -= first;
		arr[i + 1] -= first;
		arr[i + 2] -= first;
		result += 7 * first;
		int second = min(arr[i], arr[i + 1]);
		int gap = arr[i + 1] - arr[i + 2];
		arr[i] -= second;
		arr[i + 1] -= second;
		result += 5 * second;
		result += 3 * arr[i];
		arr[i] = 0;
	}
	int second = min(arr[n - 2], arr[n - 1]);
	arr[n - 2] -= second;
	arr[n - 1] -= second;
	result += 5 * second;
	result += 3 * arr[n - 2];
	result += 3 * arr[n - 1];
	cout << result;
}