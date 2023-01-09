#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> backTracking;
void BackTracking(int startIndex, int count)
{
	if (count == m)
	{
		for (int i = 0; i < backTracking.size(); i++)
		{
			cout << backTracking[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = startIndex; i < n; i++)
	{
		backTracking.push_back(arr[i]);
		BackTracking(i, count + 1);
		backTracking.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		arr.push_back(item);
	}
	sort(arr.begin(), arr.end());
	BackTracking(0, 0);
}