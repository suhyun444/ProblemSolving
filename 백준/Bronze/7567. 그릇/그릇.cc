#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	char prev = ' ';
	int result = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (prev != s[i])result += 10;
		else result += 5;
		prev = s[i];
	}
	std::cout << result;
}