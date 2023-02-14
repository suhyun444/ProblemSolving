#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		arr.push_back(item);
	}
	vector<int> result;
	for (int i = 0; i < n; i++)
	{
		if (result.empty() || result.back() < arr[i])
			result.push_back(arr[i]);
		else
		{
			int index = lower_bound(result.begin(), result.end(), arr[i]) - result.begin();
			result[index] = arr[i];
		}
	}
	cout << result.size();
}