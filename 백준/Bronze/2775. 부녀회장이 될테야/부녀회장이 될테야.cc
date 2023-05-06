#include <iostream>

using namespace std;

int people[15][15];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<15;i++)
	{ 
		people[0][i] = i;
	}
	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			for (int k = 1; k <= j; k++)
			{
				people[i][j] += people[i - 1][k];
			}
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int k, n;
		cin >> k >> n;
		cout << people[k][n] << "\n";
	}
}