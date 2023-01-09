#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		bool good = true;
		stack<char> s;
		string input;
		getline(cin, input);
		for (int i = 0;; i++)
		{
			char c = input[i];
			if (i == 0)
				if (c == '.')
				{
					return 0;
				}
			if (c == '.')break;
			if (c == '(')
				s.push('(');
			else if (c == '[')
				s.push('[');
			else if (c == ')')
			{
				if (s.empty())
					good = false;
				else
				{
					if (s.top() == '(')
						s.pop();
					else
						good = false;
				}
			}
			else if (c == ']')
			{
				if (s.empty())
					good = false;
				else
				{
					if (s.top() == '[')
						s.pop();
					else
						good = false;
				}
			}
		}
		if (!s.empty())good = false;
		cout << ((good) ? "yes" : "no") << "\n";
	}
}