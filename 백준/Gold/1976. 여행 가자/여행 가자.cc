#include <iostream>
#include <cstring>

using namespace std;

int p[201];
int find(int cur)
{
	if (p[cur] < 0)return cur;
	return p[cur] = find(p[cur]);
}
void Merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		p[b] = a;
	}
}
int main()
{
	memset(p, -1, sizeof(p));
	int n, m;
	int adjusted;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> adjusted;
			if(adjusted)Merge(i + 1, j + 1);
		}
	}
	int num;
	cin >> num;
	int cur = find(num);
	for (int i = 0; i < m-1; i++)
	{
		cin >> num;
		if (cur != find(num))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}