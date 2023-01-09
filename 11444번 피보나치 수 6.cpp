#include <iostream>

using namespace std;

struct Matrix2x2 {
	Matrix2x2()
	{
		element[0][0] = 0;
		element[0][1] = 0;
		element[1][0] = 0;
		element[1][1] = 0;
	}
	long long element[2][2];
};

Matrix2x2 mul(Matrix2x2 a, Matrix2x2 b)
{
	Matrix2x2 c = Matrix2x2();
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				c.element[i][j] += a.element[i][k] * b.element[k][j];
			}
			c.element[i][j] %= 1000000007;
		}
	}
	return c;
}

int main()
{
	long long n;
	cin >> n;
	Matrix2x2 ans;
	ans.element[0][0] = 1;
	ans.element[0][1] = 0;
	ans.element[1][0] = 0;
	ans.element[1][1] = 1;
	Matrix2x2 a;
	a.element[0][0] = 1;
	a.element[0][1] = 1;
	a.element[1][0] = 1;
	a.element[1][1] = 0;

	while (n > 0)
	{
		if (n % 2 == 1)
			ans = mul(ans, a);
		a = mul(a, a);
		n /= 2;
	}
	cout << ans.element[0][1];
}