#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001];
int main()
{
	int cur = 1;
	int count = 0;
	for (int i = 0; i < 1001; ++i)
	{
		arr[i] = cur;
		++count;
		if (count == cur)
		{
			++cur;
			count = 0;
		}
	}
	int a, b;
	cin >> a >> b;
	int result = 0;
	for (int i = a - 1; i < b; ++i)
	{
		result += arr[i];
	}
	cout << result;
}