#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, l;
	vector<int> rest;
	rest.push_back(0);
	cin >> n >> m >> l;
	for (int i = 0;i < n;i++) {
		int item;
		cin >> item;
		rest.push_back(item);
	}
	rest.push_back(l);
	sort(rest.begin(), rest.end());
	int lo = 0;
	int hi = l;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt = 0;
		for (int i = 1;i < rest.size();i++) {
			cnt += (rest[i] - rest[i - 1] - 1) / mid;
		}
		if (cnt > m) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	cout << hi;
}