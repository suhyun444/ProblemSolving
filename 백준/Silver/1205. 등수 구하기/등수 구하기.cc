#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
	return a > b;
}
int main()
{
	int n, target, p;
	cin >> n >> target >> p;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	arr.push_back(target);
	sort(arr.begin(), arr.end(),Compare);
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == target)
		{
			int count = 0;
			int index = i;
			while (++index < arr.size() && arr[index] == target)
				count++;
			if (i + 1 + count > p)
				cout << "-1";
			else cout << i + 1;
			break;
		}
	}
}
