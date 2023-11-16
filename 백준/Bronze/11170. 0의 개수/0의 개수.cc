#include <iostream>
#include <vector>

using namespace std;

int alpha[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int result = 0;
		if (a == 0)result++;
		for (int i = a; i <= b; ++i)
		{
			int temp = i;
			while (temp > 0)
			{
				if (temp % 10 == 0)result++;
				temp /= 10;
			}
		}
		cout << result << "\n";
	}
}