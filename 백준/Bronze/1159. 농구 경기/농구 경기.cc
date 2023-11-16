#include <iostream>
#include <vector>

using namespace std;

int alpha[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		alpha[s[0] - 'a']++;
	}
	bool canMake = false;
	for (int i = 0; i < 26; ++i)
	{
		if (alpha[i] >= 5)
		{
			canMake = true;
			cout << (char)('a' + i);
		}
	}
	if (!canMake)cout << "PREDAJA";
}