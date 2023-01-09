#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int adj[101][101];
int result[101];
bool visited[101];
int main()
{
	cin >> n >> m;
	for(int i=0;i<101;i++)
		for (int j = 0; j < 101; j++) {
			if (i == j)continue;
			adj[i][j] = 1e9;
		}
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	int minPeople = 1;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1;j <= n; j++)
			{
				if (adj[i][k] + adj[k][j] < adj[i][j])
				{
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
	int minValue = 2e9;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += adj[i][j];
		}
		if (minValue > sum)
		{
			minValue = sum;
			ans = i;
		}
	}
	cout << ans;
}