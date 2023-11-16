#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)q.push(i);
	long long count = 1;
	while (q.size() > 1)
	{
		long long l = count * count * count;
		l--;
		l %= q.size();
		for (int i = 0; i < l; ++i)
		{
			q.push(q.front());
			q.pop();
		}
		q.pop();
		count++;
	}
	cout << q.front();
}
