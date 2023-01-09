#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(10);
	int t;
	vector<pair<double, double>> v;
	cin >> t;
	while (t--) {
		double result = 2e9;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}
		for (int i = 0; i < n- 1; i++) {
			for (int j = i + 1; j < n; j++) {
				result = min(result, sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2)));
			}
		}
		cout << result << "\n";
		v.clear();
	}
}