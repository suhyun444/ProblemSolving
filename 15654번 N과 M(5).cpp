#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
bool visited[8];
vector<int> backTracking;
void BackTracking(int count)
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
	for (int i = 0; i < n; i++)
	{
		if (visited[i])continue;
		backTracking.push_back(arr[i]);
		visited[i] = true;
		BackTracking(count + 1);
		visited[i] = false;
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
	BackTracking(0);
}