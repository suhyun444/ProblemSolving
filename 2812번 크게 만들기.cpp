#include <iostream>
#include <vector>

using namespace std;
/*
10 5
9993333932

ans : 99993
반례 가능한 크기보다 더 많이 들어간다
k개 를 뺏다면 result에 더이상 넣어주지 않는걸로 해결 가능할듯함
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> arr;
	vector<int> result;
	int n, k;
	cin >> n >> k;
	int size = n - k;
	string num;
	cin >> num;
	for (int i = num.size() - 1; i >= 0; i--)
	{
		arr.push_back(num[i] - '0');
	}
	int cnt = 0;
	while (!arr.empty())
	{
		int cur = arr.back();
		arr.pop_back();
		while (!result.empty() && result.back() < cur && k > 0)
		{
			result.pop_back();
			k--;
		}
		result.push_back(cur);
	}
	for (int i = 0; i < size; i++)
	{
		cout << result[i];
	}
}