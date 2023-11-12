#include <iostream>
#include <queue>
#include <algorithm>

using namespace std; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int> pq;
	int n,h,t;
	cin >> n >> h >> t;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		pq.push(a);
	}
	int count = 0;
	while (t--)
	{
		int top = pq.top();
		if (top < h)break;
		if (top == 1)break;
		pq.pop();
		pq.push(top / 2);
		count++;
	}
	int max = pq.top();
	if (max < h)
	{
		cout << "YES\n";
		cout << count;
	}
	else
	{
		cout << "NO\n";
		cout << max;
	}
}