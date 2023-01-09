#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int cache[501][501];
vector<pair<int, int>> v;
int solve(int s, int e) {
	if (s + 1 == e)	return v[s].first * v[e].first * v[e].second;
	int& ret = cache[s][e];
	if (ret != -1)return ret;
	ret = 2e9;
	for (int i = s + 1; i < e; i++) {
		ret = min(ret, solve(s, i) + solve(i,e));
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	cout << solve(0, n-1);
}