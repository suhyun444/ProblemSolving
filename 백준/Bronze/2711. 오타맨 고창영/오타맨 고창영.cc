#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		for (int i = 0; i < s.length(); ++i)
		{
			if (i == n - 1)continue;
			cout << s[i];
		}
		cout << "\n";
	}
}