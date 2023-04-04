#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long s;
	long long sum = 0;
	int result = 0;
	cin >> s;
	if (s == 1)
	{
		cout << "1";
		return 0;
	}
	for (int i = 1; i <= s; i++)
	{
		if (sum + i > s)
		{
			cout << result;
			break;
		}
		sum += i;
		result++;
	}
}