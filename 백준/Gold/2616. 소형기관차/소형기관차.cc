#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, maxCount;
vector<int> weight;
int cache[3][50001];
int solve(int numOfTrain, int index)
{
	if (numOfTrain == 3)return 0;
	if (index + maxCount > n)return -1e9;
	int& ret = cache[numOfTrain][index];
	if (ret != -1)return ret;
	ret = max(solve(numOfTrain, index + 1), solve(numOfTrain + 1, index + maxCount) + weight[index + maxCount] - weight[index]);
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	weight.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		weight.push_back(item);
	}
	for (int i = 0; i < n; i++)weight[i + 1] += weight[i];
	cin >> maxCount;
	cout << solve(0, 0);
}
