#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int result = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		result = max(result, arr[i] * (n - i));
	}
	cout << result;
}