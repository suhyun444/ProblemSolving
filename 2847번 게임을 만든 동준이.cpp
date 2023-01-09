#include <iostream>

using namespace std;

int main() {
	int n, arr[100], result = 0;cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = n-2; i >=0; i--) {
		while (arr[i] >= arr[i + 1]) {
			arr[i]--;
			result++;
		}
	}
	cout << result;
}