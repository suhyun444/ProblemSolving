#include <iostream>
#include <algorithm>

using namespace std;
int dist[101][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 101; i++)for (int j = 0; j < 101; j++)if(i != j)dist[i][j] = 1e9;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i < 101; i++)for (int j = 1; j < 101; j++) {
		dist[i][j] = min(dist[i][j], dist[j][i]); dist[j][i] = dist[i][j];
	}
	int result;
	for (int i = 1; i <= n; i++) {
		result = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] >= 1e9)result++;
		}
		cout << result << "\n";
	}
}