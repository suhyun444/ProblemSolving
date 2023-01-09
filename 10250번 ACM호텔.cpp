#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int h, w, n;
		cin >> h >> w >> n;
		int ho = n / h;
		ho++;
		n %= h;
		if (n == 0)
		{
			n = h;
			ho--;
		}
		if (ho < 10)
		{
			cout << n << "0" << ho << "\n";
		}
		else
		{
			cout << n << ho << "\n";
		}
	}
}