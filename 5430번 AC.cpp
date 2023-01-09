#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n;
		cin >> n;
		deque<int> arr;
		string input;
		cin >> input;
		bool reverse = false;
		for (int i = 1; i < input.length() - 1; i++)
		{
			int startIndex = i;
			while (input[i] != ',' && i < input.length() - 1)
			{
				i++;
			}
			string temp = input.substr(startIndex, i - startIndex);
			arr.push_back(stoi(temp));
		}
		bool isError = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'R')
					reverse = !reverse;
			if (s[i] == 'D')
			{
				if (arr.empty())
				{
					isError = true;
					cout << "error\n";
					break;
				}
				else
				{
					if (!reverse)arr.pop_front();
					else arr.pop_back();
				}
			}
		}
		if (isError)continue;
		cout << "[";
		int size = arr.size();
		if (reverse)
		{
			for (int i = size - 1; i > 0; i--)
			{
				cout << arr[i] << ",";
			}
			if (!arr.empty())cout << arr.front() << "]\n";
			else cout << "]\n";
		}
		else
		{
			for (int i = 0; i < size - 1; i++)
			{
				cout << arr[i] << ",";
			}
			if (!arr.empty())cout << arr.back() << "]\n";
			else cout << "]\n";
		}
	}
}