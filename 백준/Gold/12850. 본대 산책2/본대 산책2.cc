#include <iostream>

using namespace std;

struct Matrix
{
	long long m[8][8];
	Matrix()
	{
		for (int i = 0; i < 8; ++i)	for (int j = 0; j < 8; ++j)	this->m[i][j] = 0;
	}
	Matrix(long long m[8][8])
	{
		for (int i = 0; i < 8; ++i)for (int j = 0; j < 8; ++j)this->m[i][j] = m[i][j];
	}
	Matrix operator*(const Matrix& o)
	{
		Matrix result;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				for (int k = 0; k < 8; ++k)
				{
					result.m[i][j] += m[i][k] * o.m[k][j];
					result.m[i][j] %= 1000000007;
				}
			}
		}
		return result;
	}
};
Matrix adj;
Matrix tmp;
long long ans[8][8] = {
	{1,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,1}
};
long long a[8][8] = { 
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,0,1},
	{0,0,0,1,1,0,1,0},
	{0,0,0,0,0,1,0,1},
	{0,0,0,0,1,0,1,0} 
};
int main()
{
	adj = Matrix(ans);
	tmp = Matrix(a);
	int d;
	cin >> d;
	while (d > 0)
	{
		if (d % 2 == 1)
		{
			adj = adj * tmp;
		}
		tmp = tmp * tmp;
		d /= 2;
	}
	cout << adj.m[0][0];
}