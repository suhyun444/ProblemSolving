#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k, n;
vector<int> arr;
int ParametricSearch() {
	long long ret = 0;
	long long lo = 0, hi = arr.back();
	hi++;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		int num = 0;
		for (int i = 0; i < k; i++) {
			num += arr[i] / mid;
		}
		if (num < n) {
			hi = mid;
		}
		else {
			lo = mid;
			ret = mid;
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	cout << ParametricSearch();
}