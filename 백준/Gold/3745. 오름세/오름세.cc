#include <iostream>
#include <vector>

using namespace std;

int arr[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		vector<int> lis;
		lis.push_back(arr[0]);
		int result = 1;
		for (int i = 1; i < n; i++)
		{
			if (lis.back() < arr[i])
			{
				lis.push_back(arr[i]);
				result++;
			}
			else
			{
				int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
				lis[index] = arr[i];
			}
		}
		cout << result << "\n";
	}
}