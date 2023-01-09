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
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int aIndex = 0;
		int bIndex = 0;
		while (true)
		{
			if (m * aIndex + x > n * bIndex + y)
			{
				bIndex++;
			}
			else if (m * aIndex + x < n * bIndex + y)
			{
				aIndex++;
			}
			if (m * aIndex + x == n * bIndex + y)
			{
				cout << m * aIndex + x << "\n";
				break;
			}
			if (aIndex > 40000 || bIndex > 40000)
			{
				cout << "-1\n";
				break;
			}
		}
	}
}