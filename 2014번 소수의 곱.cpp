#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

vector<int> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
		pq.push(a);
	}
	for (int i = 0; i < n - 1; i++)
	{
		int cur = pq.top();
		for (int j = 0; j < k; j++)
		{
			long long num = cur * 1LL * arr[j];
			if (num < pow(2, 31))
			{
				pq.push(num);
			}
		}
		while (cur == pq.top())
			pq.pop();
	}
	cout << pq.top();
}