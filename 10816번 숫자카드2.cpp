#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<int, int> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		if (m.find(item) == m.end())
		{
			m.insert({ item, 1 });
		}
		else
		{
			m[item]++;
		}
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int item;
		cin >> item;
		if (m.find(item) == m.end())
		{
			cout << "0 ";
		}
		else
		{
			cout << m[item] << " ";
		}
	}
}