#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string name;
	cin >> n;
	cin >> name;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += name[i] - 'A' + 1;
	}
	cout << sum;
}