#include <iostream>
#include <vector>

using namespace std;

int alpha[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); ++i)
		alpha[s1[i] - 'a']++;
	for (int i = 0; i < s2.length(); ++i)
		alpha[s2[i] - 'a']--;
	int result = 0;
	for (int i = 0; i < 26; ++i)
		result += abs(alpha[i]);
	cout << result;
}
