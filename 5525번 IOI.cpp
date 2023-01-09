#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> arr;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'I')
		{
			int size = 0;
			while (true)
			{
				if (i + 2 < s.length())
				{
					if (s[i + 1] == 'O' && s[i + 2] == 'I')
					{
						size++;
						i += 2;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			if (size != 0)
			{
				arr.push_back(size);
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] >= n)
		{
			int cur = arr[i] - n + 1;
			sum += cur;
		}
	}
	cout << sum;
}