#include <iostream>

using namespace std;

int main()
{
	int dp[100001];
	for (int i = 0; i < 100001; i++)dp[i] = 0;
	int n;
	cin >> n;
	for (int i = 1; i * i <= n; i++)
		dp[i * i] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (dp[i] == 0)
		{
			for (int j = 1; j * j <= i; j++)
			{
				if (dp[i] == 0)
				{
					dp[i] = dp[j * j] + dp[i - j * j];
				}
				else
				{
					dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
				}
			}
		}
	}
	cout << dp[n];
}