#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> dist(n - 1);
	vector<int> city(n);
	for (int i = 0; i < n - 1; ++i)
		cin >> dist[i];
	for (int i = 0; i < n; ++i)
		cin >> city[i];

	int minCost = city[0];
	long long result = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		minCost = min(minCost, city[i]);
		result += 1LL * minCost * dist[i];
	}
	cout << result;
}