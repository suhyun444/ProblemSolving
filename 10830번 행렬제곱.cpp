#include <iostream>

using namespace std;

int n;
int arr[5][5];
int temp[5][5];
int ans[5][5];
 void mul(int a[5][5], int b[5][5])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				temp[i][j] += a[i][k] * b[k][j];
			}
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = temp[i][j];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long B;
	cin >> n >> B;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			ans[i][j] = 0;
		}
	}
	ans[0][0] = 1; ans[1][1] = 1; ans[2][2] = 1; ans[3][3] = 1; ans[4][4] = 1;

	while (B > 0)
	{
		if (B % 2 == 1)
		{
			mul(ans, arr);
		}
		mul(arr, arr);
		B /= 2;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}