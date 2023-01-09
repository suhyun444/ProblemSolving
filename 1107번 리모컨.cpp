#include <iostream>

using namespace std;

int n, m;
int nSize = 1;
int minAns = 2e9;
bool number[10];
void backtracking(int count,int num)
{
	if (count != 0)
	{
		minAns = min(minAns,abs(num - n) + count);
	}
	if(count == nSize + 1)return;
	for (int i = 0; i < 10; i++)
	{
		if (number[i] == false)continue;
		backtracking(count + 1, num * 10 + i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 10; i++)number[i] = true;
	cin >> n >> m;
	int temp = n;
	temp /= 10;
	while (temp != 0)
	{
		nSize++;
		temp /= 10;
	}
	for (int i = 0; i < m; i++)
	{
		int item;
		cin >> item;
		number[item] = false;
	}
	minAns = abs(100 - n);
	backtracking(0, 0);
	cout << minAns;
}