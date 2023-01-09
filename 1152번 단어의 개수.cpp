#include <iostream>
#include <string>
using namespace std;

int main()
{
	int alphabet[27];
	for (int i = 0; i < 27; i++)alphabet[i] = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			alphabet[s[i] - 'A']++;
		}
		else if('a' <= s[i] && s[i] <= 'z')
		{
			alphabet[s[i] - 'a']++;
		}
	}
	int maxCount = 0;
	int maxCountIndex = 0;
	for (int i = 0; i < 27; i++)
	{
		if (maxCount < alphabet[i])
		{
			maxCount = alphabet[i];
			maxCountIndex = i;
		}
	}
	for (int i = 0; i < 27; i++)
	{
		if (alphabet[i] != 0 && i != maxCountIndex && maxCount == alphabet[i])
		{
			cout << "?";
			return 0;
		}
	}
	cout << char('A' + maxCountIndex);
}