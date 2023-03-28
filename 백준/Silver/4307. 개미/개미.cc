#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int l, n;
		int minTime = 0;
		int maxTime = 0;
		cin >> l >> n;
		for (int i = 0; i < n; i++)
		{
			int dist;
			cin >> dist;
			minTime = max(minTime, min(dist,l - dist));
			maxTime = max(maxTime, max(dist,l - dist));
		}
		cout << minTime << " " << maxTime << "\n";
	}
}