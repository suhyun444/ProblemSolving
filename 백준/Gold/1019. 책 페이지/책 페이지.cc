#include <iostream>

using namespace std;

int pageCount[10];
void Func(int num,int power)
{
	while (num > 0)
	{
		pageCount[num % 10] += power;
		num /= 10;
	}
}
int main()
{
	int l = 1, r;
	cin >> r;
	int power = 1;
	while (l <= r)
	{
		while (l % 10 != 0 && l <= r)
		{
			Func(l,power);
			l++;
		}
		if (l > r)
		{
			break;
		}
		while (r % 10 != 9)
		{
			Func(r,power);
			r--;
		}
		r /= 10;
		l /= 10;
		for (int i = 0; i < 10; ++i)
		{
			pageCount[i] += (r - l + 1) * power;
		}
		power *= 10;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << pageCount[i] << " ";
	}
}