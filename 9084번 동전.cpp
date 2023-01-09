#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> coin;
int N, M;
int cache[21][10001];
int solve(int n, int m) {
	if (m == M)return 1;
	int& ret = cache[n][m];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = n; i < N; i++) {
		if (m + coin[i] <= M)ret += solve(i, m + coin[i]);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		int item;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> item;
			coin.push_back(item);
		}
		cin >> M;
		cout << solve(0, 0) << "\n";
		coin.clear();
	}
}