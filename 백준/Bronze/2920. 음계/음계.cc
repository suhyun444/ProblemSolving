#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 8; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	for (int i = 1; i < 9; i++)
	{
		if (arr[i - 1] != i)break;
		if (i == 8)
		{
			cout << "ascending";
			return 0;
		}
	}
	int index = 0;
	for (int i = 8; i > 0; i--)
	{
		if (arr[index] != i)break;
		if (i == 1)
		{
			cout << "descending";
			return 0;
		}
		index++;
	}
	cout << "mixed";
}