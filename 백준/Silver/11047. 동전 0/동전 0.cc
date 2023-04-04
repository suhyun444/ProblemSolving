#include <iostream>
#include <vector>
using namespace std;

vector<int> coin;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int cost;
		cin >> cost;
		coin.push_back(cost);
	}
	int result = 0;
	int coinIndex = n - 1;
	while (k > 0)
	{
		result += k / coin[coinIndex];
		k %= coin[coinIndex];
		coinIndex--;
	}
	cout << result;
}