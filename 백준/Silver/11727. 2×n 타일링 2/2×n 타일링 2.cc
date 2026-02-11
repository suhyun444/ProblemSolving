#include <iostream>
#include <cstring>

using namespace std;

int cache[1001];
int solve(int n) {
	if (n == 0)return 1;
	else if (n < 0) return 0;
	int& ret = cache[n];
	if (ret != -1)return ret;
	return ret = (solve(n - 1) + solve(n - 2) + solve(n - 2)) % 10007;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	int n;
	cin >> n;
	cout << solve(n);
}