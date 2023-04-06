#include <iostream>
#include <vector>

using namespace std;

vector<int> trees;
int n;
long long m;
bool func(int mid)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += max(trees[i] - mid,0);
	}
	return sum >= m;
}
int main()
{
	int maxHeight = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		maxHeight = max(maxHeight, a);
		trees.push_back(a);
	}
	int result = 0;
	int lo = -1;
	int hi = maxHeight;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (func(mid))
		{
			lo = mid;
			result = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << result;

}