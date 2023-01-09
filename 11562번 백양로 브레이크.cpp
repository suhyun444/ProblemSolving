#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dist[251][251];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 251; i++)for (int j = 0; j < 251; j++)if(i!=j)dist[i][j] = 1e9;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 0)
		{
			dist[a][b] = 0;
			dist[b][a] = 1;
		}
		else
		{
			dist[a][b] = 0;
			dist[b][a] = 0;
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << "\n";
	}
}