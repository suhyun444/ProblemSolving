#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue <pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> pq;
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		pq.push({ a ,i});
		while (pq.top().second <= i - l)
			pq.pop();
		cout << pq.top().first << " ";
	}
}