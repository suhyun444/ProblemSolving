#include <iostream>

using namespace std;

long long a, b, c;
long long solve(int count)
{
	if (count == 0) return 1;
	if (count % 2 == 1)
	{
		return a * solve(count - 1) % c;
	}
	else
	{
		long long half = solve(count / 2);
		return half * half % c;
	}
}
int main()
{
	cin >> a >> b >> c;
	cout << solve(b);
}