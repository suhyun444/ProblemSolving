#include <iostream>
#include <vector>
#include <string>

using namespace std;

int fail[1000001];
int main()
{
	string s,w;
	getline(cin, s);
	getline(cin, w);
	for (int i = 1, j = 0; i < w.size(); ++i) {
		while (j > 0 && w[i] != w[j]) j = fail[j - 1];
		if (w[i] == w[j]) fail[i] = ++j;
	}
	vector<int> result;
	for (int i = 0, j = 0; i < s.size(); ++i)
	{
		while (j > 0 && s[i] != w[j])
			j = fail[j - 1];
		if (s[i] == w[j])
		{
			if (j == w.size() - 1)
			{
				result.push_back(i - w.size() + 2);
				j = fail[j];
			}
			else
				++j;
		}
	}
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
}
