#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int visited[10001];
int n, m;
vector<int> backTracking;
void BackTracking( int count)
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
	for (int i = 0; i < arr.size(); i++)
	{
		if (visited[arr[i]] > 0)
		{
			visited[arr[i]]--;
			backTracking.push_back(arr[i]);
			BackTracking( count + 1);
			backTracking.pop_back();
			visited[arr[i]]++;
		}
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
		if (visited[item] < m)
		{
			if (visited[item] == 0)
			{
				arr.push_back(item);
			}
			visited[item]++;
		}
	}
	sort(arr.begin(), arr.end());
	BackTracking( 0);
}