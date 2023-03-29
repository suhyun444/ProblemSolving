#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,max_n = -2e9,min_n = 2e9;
vector<int> arr;

void solve(int start,int num,int plus,int minus,int multi,int divi) {
	if (start == n) {
		max_n = max(max_n, num);
		min_n = min(min_n, num);
	}
	if (plus > 0) solve(start + 1, num + arr[start], plus - 1, minus, multi, divi);
	if (minus > 0) solve(start + 1, num - arr[start], plus, minus - 1, multi, divi);
	if (multi > 0)solve(start + 1, num * arr[start], plus, minus, multi - 1, divi);
	if (divi > 0) solve(start + 1, num / arr[start], plus, minus, multi, divi - 1);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int oper[4];
	cin >> n;
	for (int i = 0;i < n;i++) {
		int item;
		cin >> item;
		arr.push_back(item);
	}
	cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];
	solve(1, arr[0], oper[0], oper[1], oper[2], oper[3]);
	cout << max_n << "\n" << min_n;
}