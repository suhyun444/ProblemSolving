#include <iostream>

using namespace std;


bool use[21][21];
int dist[21][21];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
			use[i][j] = true;
		}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (i == k || j == k)continue;
				if (dist[i][j] == dist[i][k] + dist[k][j]) use[i][j] = false;
				else if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					cout << "-1";
					return 0;
				}
			}
	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (use[i][j])
				result += dist[i][j];
	cout << result;
}