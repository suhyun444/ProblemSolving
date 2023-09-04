#include <iostream>
#include <map>
#include <vector>

using namespace std;

int mid;
int n, s;
map<int, long long> m;
vector<int> arr;
void left(int index, int num,bool flag)
{
	if (index == mid)
	{
		if (!flag)return;
		if (m.find(num) == m.end())
		{
			m.insert({ num, 1 });
		}
		else
		{
			++m[num];
		}
		return;
	}
	left(index + 1, num, flag & true);
	left(index + 1, num + arr[index],true);
}
long long Right(int index, int num,bool flag)
{
	if (index == n)
	{
		int need = s - num;
		if (m.find(need) == m.end())
		{
			if (need == 0)return flag;
			return 0;
		}
		if (s == num)return m[need] + flag;
		return m[need];
	}
	return Right(index + 1, num,flag & true) + Right(index + 1, num + arr[index],true);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	mid = n / 2;
	left(0, 0,false);
	cout << Right(mid, 0,false);	
}