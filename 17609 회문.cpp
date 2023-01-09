#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int lo = 0;
		int hi = s.length() - 1;
		bool alreadyChange = false;
		int type = 0;
		while (lo <= hi)
		{
			if (s[lo] != s[hi])
			{
				type = 1;
				if (alreadyChange)
				{
					type = 2;
					break;
				}
				if (s[lo] == s[hi - 1])
				{
					hi--;
					alreadyChange = true;
				}
				else
				{
					type = 2;
					break;
				}
			}
			lo++;
			hi--;
		}
		lo = 0;
		hi = s.length() - 1;
		alreadyChange = false;
		int secondType = 0;
		while (lo <= hi)
		{
			if (s[lo] != s[hi])
			{
				secondType = 1;
				if (alreadyChange)
				{
					secondType = 2;
					break;
				}
				if (s[lo + 1] == s[hi])
				{
					lo++;
					alreadyChange = true;
				}
				else
				{
					secondType = 2;
					break;
				}
			}
			lo++;
			hi--;

		}
		cout << min(type,secondType) << "\n";
	}
}