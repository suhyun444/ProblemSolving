#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> arr1;
vector<int> arr2;
map<int,int> m1;
map<int, int> m2;

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
		{
			int key = arr1[j] - arr1[i];
			if (m1.find(key) != m1.end())
				m1[key]++;
			else
				m1.insert({key, 1});
		}

	for (int i = 0; i < m; i++)
		for (int j = i + 1; j <= m; j++)
		{
			int key = arr2[j] - arr2[i];
			if (m2.find(key) != m2.end())
				m2[key]++;
			else
				m2.insert({ key, 1 });
		}

	long long result = 0;
	for (pair<int,int> cur : m1)
	{
		int key = t - cur.first;
		if (m2.find(key) != m2.end())
		{
			result += 1LL * cur.second * m2[key];
		}
	}
	cout << result;
}