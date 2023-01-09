#include <iostream>

using namespace std;

int main()
{
	string s;
	string bomb;
	string ans;
	cin >> s;
	cin >> bomb;
	for (int i = 0; i < s.size(); i++)
	{
		bool isBomb = false;
		ans.push_back(s[i]);
		if (s[i] == bomb.back())
		{
			isBomb = true;
			for (int j = bomb.size() - 1; j >= 0; j--)
			{
				if (i - bomb.size() + 1 + j < 0)
				{
					isBomb = false;
					break;
				}
				if (ans[ans.size() - bomb.size() + j] != bomb[j])
				{
					isBomb = false;
					break;
				}
			}
		}
		if (isBomb)
		{
			for (int j = 0; j < bomb.size(); j++)
			{
				ans.pop_back();
			}
		}
	}
	if (ans == "")cout << "FRULA";
	else cout << ans;
}