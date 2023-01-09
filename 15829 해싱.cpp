#include <iostream>
#include <math.h>
#define MOD 1234567891
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	long long r = 1;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		int cur = (c - 'a') + 1;
		sum += 1LL* cur * r;
		r *= 31;
		r %= MOD;
		sum %= MOD;
	}
	cout << sum;
}
