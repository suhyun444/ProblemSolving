#include <iostream>
#include <vector>

using namespace std;

int main() {
	string result;
	pair<int, int> minCostNumber = { -1,9999 };
	int n,money;
	cin >> n;
	vector<int> cost(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		if (cost[i] < minCostNumber.second) {
			minCostNumber = { i,cost[i] };
		}
	}
	cin >> money;
	while (money > 0) {
		if (money - minCostNumber.second < 0)break;
		money -= minCostNumber.second;
		result += (char)minCostNumber.first;
	}
	if (result[0] != '0') {
		for (int i = n - 1; i > minCostNumber.first; i--) {
			if (money + minCostNumber.second >= cost[i]) {
				result[0] = (char)i;
				break;
			}
		}
	}
	else {
		while (true) {
			bool flag = false;
			for (int i = n - 1; i >= 0; i--) {
				if (money + minCostNumber.second >= cost[i]) {
					result[0] = (char)i;
					flag = true;
					break;
				}
			}
			if (flag)break;
			else {
				money += minCostNumber.second;
				result = result.substr(0, result.size() - 1);
			}
		}
	}
	cout << result;
}