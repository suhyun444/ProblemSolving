#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main()
{
	vector<int> plus;
	vector<int> minus;
	plus.push_back(0);
	minus.push_back(0);
	int n, item, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> item;
		if (item > 0)plus.push_back(item);
		else minus.push_back(item);
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end(), compare);
	int result = 0;
	if (plus.back() > abs(minus.back())) {
		result += plus.back();
		for (int i = 0; i < m; i++)if (!plus.empty())plus.pop_back();
	}
	else {
		result -= minus.back();
		for (int i = 0; i < m; i++)if (!minus.empty())minus.pop_back();
	}
	while (!minus.empty()) {
		result -= minus.back() * 2;
		for (int i = 0; i < m; i++) {
			if (!minus.empty())	minus.pop_back();
			else break;
		}
	}
	while (!plus.empty()) {
		result += plus.back() * 2;
		for (int i = 0; i < m; i++) {
			if (!plus.empty())plus.pop_back();
			else break;
		}
	}
	cout << result;
}