#include <iostream>

using namespace std;

int num[9] = { 0,0,1,7,4,2,0,8,10 };
long long cache[101];
void SolveMin()
{
	for (int i = 0; i < 101; i++)cache[i] = 9e15;
	for(int i=1;i<9;i++)
	{
		cache[i] = num[i];
	}
	cache[6] = 6;
	for (int i = 9; i < 101; i++)
	{
		for (int j = 2; j < 8; j++)
		{
			cache[i] = min(cache[i], cache[i - j] * 10 + num[j]);
		}
	}
}
string SolveMax(int n)
{
	string result = "";
	if (n % 2 == 1)
	{
		n -= 3;
		result += "7";
	}
	while (n != 0)
	{
		n -= 2;
		result += "1";
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	SolveMin();
	while (t--)
	{
		int n;
		cin >> n;
		cout << cache[n] << " " << SolveMax(n) << "\n";
	}
}
