#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> arr;
	stack<int> s;
	vector<char> ans;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		arr.push_back(item);
	}
	int index = 0;
	int curNumber = 1;
	s.push(curNumber);
	curNumber++;
	ans.push_back('+');
	while (index != n)
	{
		if (s.empty())
		{
			s.push(curNumber++);
			ans.push_back('+');
		}
		else if (s.top() < arr[index])
		{
			s.push(curNumber++);
			ans.push_back('+');
		}
		else if (s.top() == arr[index])
		{
			index++;
			ans.push_back('-');
			s.pop();
		}
		else if (s.top() > arr[index])
		{
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]<<"\n";
	}
}