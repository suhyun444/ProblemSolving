#include <iostream>
#include <cstring>

using namespace std;

int cache[1001];

int solve(int n)
{
	cache[1] = cache[3] = 1;
	for (int i = 4; i <= n; i++)
		if (!cache[i - 1] && !cache[i - 3] && !cache[i - 4])
			cache[i] = 1;
		
	return cache[n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cout << ((solve(n)) ? "CY" : "SK");
}