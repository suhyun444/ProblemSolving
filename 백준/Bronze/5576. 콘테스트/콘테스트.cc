#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[10];
	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 10; ++i)
			cin >> arr[i];
		sort(arr, arr + 10);
		cout << arr[7] + arr[8] + arr[9] << " ";
	}
}