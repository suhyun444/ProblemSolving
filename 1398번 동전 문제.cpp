#include <iostream>
#include <cstring>

using namespace std;

int cache[100];
int solve(int cost) {
	if (cost == 0)return 0;
	int& ret = cache[cost];
	if (ret != -1)return ret;
	ret = 2e9;
	if (cost >= 25)ret = min(ret, solve(cost - 25) + 1);
	if (cost >= 10)ret = min(ret, solve(cost - 10) + 1);
	ret = min(ret, solve(cost - 1) + 1);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;
	while (t--) {
		int result = 0;
		long long cost;
		cin >> cost;
		while(cost != 0){
			result += solve(cost % 100);
			cost /= 100;
		}
		cout << result << "\n";
	}
}	