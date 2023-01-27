#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
vector<pair<int, int>> painting;
vector<int> heights;
int cache[300001];
int Solve(int cur)
{
	if (cur == n)return 0;
	int& ret = cache[cur];
	if (ret != -1)return ret;
	int requiredHeight = painting[cur].first + s;
	int nextIndex = lower_bound(heights.begin() + cur, heights.end(), requiredHeight) - heights.begin();
	ret = max(Solve(cur + 1) , Solve(nextIndex) + painting[cur].second);
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		heights.push_back(a);
		painting.push_back({ a,b });
	}
	sort(heights.begin(), heights.end());
	sort(painting.begin(), painting.end());
	heights.push_back(2e9);
	painting.push_back({ 2e9,0 });
	cout << Solve(0);
}