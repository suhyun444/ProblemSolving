#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int weights[2001];
bool Compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if (a.first.second == b.first.second)return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,c;
	cin >> n >> c;
	int m;
	cin >> m;
	vector<pair<pair<int, int>, int>> packageInfo;
	for (int i = 0; i < m; i++)
	{
		int s, e, weight;
		cin >> s >> e >> weight;
		packageInfo.push_back({ {s,e},weight });
	}
	sort(packageInfo.begin(), packageInfo.end(),Compare);
	int result = 0;
	int curDay = 0;
	for (int i = 0; i < packageInfo.size(); i++)
	{
		int maxCanPackageWeight = 0;
		for (int j = packageInfo[i].first.first; j < packageInfo[i].first.second; j++)
			maxCanPackageWeight = max(maxCanPackageWeight, weights[j]);

		int canPackageWeight = min(packageInfo[i].second, c - maxCanPackageWeight);
		result += canPackageWeight;
	
		for (int j = packageInfo[i].first.first; j < packageInfo[i].first.second; j++)
			weights[j] += canPackageWeight;
	}
	cout << result;

}