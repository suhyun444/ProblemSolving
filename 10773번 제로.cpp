#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		if (item == 0)arr.pop_back();
		else arr.push_back(item);
	}
	int sum = 0;
	for (int cur : arr)
	{
		sum += cur;
	}
	cout << sum;
}