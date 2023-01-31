#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
vector<int> arr;
int cache[2001][2001];

int Solve(int s, int e)
{
	if (s >= e)return 1;
	int& ret = cache[s][e];
	if (ret != -1)return ret;
	if (arr[s] != arr[e])return ret = 0;
	return 	ret = Solve(s + 1, e - 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		arr.push_back(item);
	}
	int t;
	cin >> t;
	while (t--)
	{
		int s, e;
		cin >> s >> e;
		cout << Solve(s - 1, e - 1) << "\n";
	}
}