#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr1;
vector<int> arr2;
vector<int> sumArr1;
vector<int> sumArr2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, m;
	cin >> t;
	cin >> n;
	arr1.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		arr1.push_back(item + arr1.back());
	}
	cin >> m;
	arr2.push_back(0);
	for (int i = 0; i < m; i++)
	{
		int item;
		cin >> item;
		arr2.push_back(item + arr2.back());
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			sumArr1.push_back(arr1[j] - arr1[i]);

	for (int i = 0; i < m; i++)
		for (int j = i + 1; j <= m; j++)
			sumArr2.push_back(arr2[j] - arr2[i]);

	long long result = 0;
	sort(sumArr2.begin(), sumArr2.end());
	for (int i = 0; i < sumArr1.size(); i++)
	{
		int findNum = t - sumArr1[i];
		int upperIndex = upper_bound(sumArr2.begin(), sumArr2.end(), findNum) - sumArr2.begin();
		int lowerIndex = lower_bound(sumArr2.begin(), sumArr2.end(), findNum) - sumArr2.begin();
		result += 1LL *upperIndex - 1LL *lowerIndex;
	}
	cout << result;
}