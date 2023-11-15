#include <iostream>

using namespace std;

bool visited[101];
int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (visited[a]) ++count;
		visited[a] = true;
	}
	cout << count;
}