#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
	bool operator()(long long a, long long b) {
		return a > b;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<long long,vector<long long>,compare> pq;
	int t,n;
	long long tmp ,result;
	cin >> t;
	while (t--) {
		result = 1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			long long a;
			cin >> a;
			pq.push(a);
		}
		while (pq.size() > 1) {
			tmp = pq.top();pq.pop();
			tmp *= pq.top(); pq.pop();
			result = ((tmp % 1000000007) *result) % 1000000007;
			pq.push(tmp);
		}
		cout << result  % 1000000007 << "\n";
		while (!pq.empty())pq.pop();
	}
}