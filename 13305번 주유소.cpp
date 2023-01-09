#include <iostream>

using namespace std;

int city[100001];
int dist[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)cin >> dist[i];
	for (int i = 0; i < n; i++)cin >> city[i];
	int curCost = city[0];
	long long result = 0;
	for (int i = 1; i < n; i++) {
		result += 1LL * dist[i] * curCost;
		if (curCost > city[i]) {
			curCost = city[i];
		}
	}
	cout << result;
}