#include <iostream>
#include <stack>

using namespace std;

stack<pair<int,int>> s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		while (!s.empty() && s.top().first < a)
		{
			ans += s.top().second;
			s.pop();
		}
		if (s.empty())s.push({ a,1 });
		else
		{
			if (s.top().first == a)
			{
				int cnt = s.top().second;
				s.pop();
				ans += cnt;
				if (!s.empty())ans++;
				s.push({ a,cnt + 1 });
			}
			else
			{
				s.push({ a,1 });
				ans++;
			}
		}
	}
	cout << ans;
}