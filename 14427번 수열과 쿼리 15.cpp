#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000003];
int Tree[4000003];
int minIndex(int a, int b) {
	if (arr[a] == arr[b]) return (a < b) ? a : b;
	return (arr[a] < arr[b]) ? a : b;
}
void Init(int n,int l,int r) {
	if (l == r) { Tree[n] = l; return; }
	int mid = (l + r) / 2;
	Init(n * 2, l, mid);
	Init(n * 2 + 1, mid + 1, r);
	Tree[n] = minIndex(Tree[n * 2], Tree[n * 2 + 1]);
}
void Upgrade(int n, int l, int r, int t) {
	if (l > t || t > r) { return; }
	if (l == r) { return; }
	int mid = (l + r) / 2;
	Upgrade(n * 2, l, mid, t);
	Upgrade(n * 2 + 1, mid + 1, r, t);
	Tree[n] = minIndex(Tree[n * 2], Tree[n * 2 + 1]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	fill(arr, arr + 400000, 2e9);
	for (int i = 1; i <= n; i++)cin >> arr[i];
	Init(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int a, b;
			cin >> a >> b;
			arr[a] = b;
			Upgrade(1, 1, n, a);
		}
		else {
			cout << Tree[1] << "\n";
		}
	}

}