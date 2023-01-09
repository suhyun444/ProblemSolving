#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int> > v;
	int t;
	cin >> t;
	while (t--) {
		int n,a,b;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int result = 1;
		pair<int, int> high = v[0];
		for (int i = 1; i < n; i++) {
			if (high.second > v[i].second) {
				result++;
				high = v[i];
			}
		}
		cout << result << "\n";
		v.clear();
	}
}