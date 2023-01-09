#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stones;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int d, n, m;
	cin >> d >> n >> m;
	stones.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		stones.push_back(a);
	}
	stones.push_back(d);
	sort(stones.begin(), stones.end()); 
	int lo = 0;
	int hi = d;
	int ret = 0;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		int cur = 0;
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (stones[i] - stones[cur] < mid)
				count++;
			else
				cur = i;
		}
		if (count > m)
		{
			hi = mid - 1;
		}
		else
		{
			ret = mid;
			lo = mid + 1;
		}
	}
	cout << ret;
}