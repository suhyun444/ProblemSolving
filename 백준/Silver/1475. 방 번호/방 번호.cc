#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int numOfDigit[10];
	for (int i = 0; i < 10; i++)numOfDigit[i] = 0;
	int n;
	cin >> n;
	while (n > 0)
	{
		numOfDigit[n % 10]++;
		n /= 10;
	}
	int ans = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == 6)
		{
			numOfDigit[6] += numOfDigit[9];
			ans = max(ans, (numOfDigit[6] % 2 == 0) ? numOfDigit[6] / 2 : numOfDigit[6] / 2 + 1);
		}
		else
		{
			ans = max(ans, numOfDigit[i]);
		}
	}
	cout << ans;
}