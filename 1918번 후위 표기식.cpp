#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	vector<char> ans;
	stack<pair<char,int>>operators;
	int stackCount = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			ans.push_back(s[i]);
		}
		if (s[i] == '(')
		{
			stackCount++;
		}
		else if (s[i] == ')')
		{
			while(!operators.empty() && operators.top().second == stackCount)
			{
				ans.push_back({ operators.top().first});
				operators.pop();
			}
			stackCount--;
		}
		else if (stackCount > 0 && (s[i] == '+' || s[i] == '-'))
		{
			while (!operators.empty() && operators.top().second == stackCount)
			{
				ans.push_back(operators.top().first);
				operators.pop();
			}
			operators.push({ s[i],stackCount });
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			if (stackCount == 0)
			{
				while (!operators.empty() && (operators.top().first == '*' || operators.top().first == '/'))
				{
					ans.push_back(operators.top().first);
					operators.pop();
				}
			}
			else
			{
				while (!operators.empty() && (operators.top().first == '*' || operators.top().first == '/') && operators.top().second == stackCount)
				{
					ans.push_back(operators.top().first);
					operators.pop();
				}
			}
			operators.push({ s[i] ,stackCount});
		}
		else if (stackCount == 0 && s[i] == '+' || s[i] == '-')
		{
			while (!operators.empty())
			{
				ans.push_back(operators.top().first);
				operators.pop();
			}
			operators.push({ s[i] ,stackCount});
		}
	}
	while (!operators.empty())
	{
		ans.push_back(operators.top().first);
		operators.pop();
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
	}
}