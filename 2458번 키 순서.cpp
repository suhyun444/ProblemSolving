#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dist[501][501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 501; i++)for (int j = 0; j < 501; j++)dist[i][j] = 1e9;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		int cur = 0;
		for (int j = 1; j <= n; j++)
			if (dist[i][j] != 1e9 || dist[j][i] != 1e9)
				cur++;
		if (cur == n - 1)result++;
	}
	cout << result;

}