#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	stack<int> s;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s.empty())
		{
			ans[i] = -1;
		}
		else
		{
			while (!s.empty() && s.top() <= arr[i])
				s.pop();
			if (s.empty())ans[i] = -1;
			else ans[i] = s.top();
		}
		s.push(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
}