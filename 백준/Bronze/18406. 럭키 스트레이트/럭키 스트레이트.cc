#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	int temp = n;
	int len = 0;
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	int l = 0, r = 0;
	for (int i = 0; i < len / 2; ++i)
	{
		l += n % 10;
		n /= 10;
	}
	for (int i = 0; i < len / 2; ++i)
	{
		r += n % 10;
		n /= 10;
	}
	cout << ((l == r) ? "LUCKY" : "READY");

}