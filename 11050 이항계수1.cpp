#include <iostream>

using namespace std;

int factorial(int n)
{
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}
int main()
{
	int n, k;
	cin >> n >> k;
	int nFactorial = factorial(n);
	int kFactorial = factorial(k);
	int nMkFactorial = factorial(n - k);
	int ans = nFactorial / (kFactorial * nMkFactorial);
	cout << ans;
}