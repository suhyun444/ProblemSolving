#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mid;
int n, s;
vector<int> resultArr;
vector<int> arr;
void leftArr(int index, int num,bool flag)
{
	if (index == mid)
	{
		if (!flag)return;
		resultArr.push_back(num);
		return;
	}
	leftArr(index + 1, num, flag & true);
	leftArr(index + 1, num + arr[index],true);
}
long long Right(int index, int num,bool flag)
{
	if (index == n)
	{
		int need = s - num;
		int s = lower_bound(resultArr.begin(), resultArr.end(), need) - resultArr.begin();
		int e = upper_bound(resultArr.begin(), resultArr.end(), need) - resultArr.begin();
		if (need == 0)return e - s + flag;
		return e - s;
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
	leftArr(0, 0,false);
	sort(resultArr.begin(), resultArr.end());
	cout << Right(mid, 0,false);	
}