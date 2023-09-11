#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long ans = n;
	for (long long i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			while (n % i == 0) n /= i;
			ans -= ans / i;
		}
	}
	if (n > 1)
		ans -= ans / n;
	cout << ans;
}