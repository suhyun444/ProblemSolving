#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> arr;
	string s;
	cin >> s;
	int index = 0;
	while (s[index] != '+' && s[index] != '-')
	{
		index++;
	}
	string tmp = s.substr(0, index);
	arr.push_back(stoi(tmp));
	for (int i = index; i < s.length();)
	{
		int flag = 0;
		if (s[i] == '+')flag = 1;
		else flag = -1;
		i++;
		int startIndex = i;
		while (s[i] != '+' && s[i] != '-' && i < s.length())
		{
			i++;
		}
		tmp = s.substr(startIndex, i - startIndex);
		arr.push_back(stoi(tmp) * flag);
	}
	bool isMinus = false;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < 0)
		{
			isMinus = true;
			sum += arr[i];
		}
		if (arr[i] > 0 && isMinus)
		{
			sum -= arr[i];
		}
		if (arr[i] > 0 && !isMinus)
		{
			sum += arr[i];
		}
	}
	cout << sum;
}