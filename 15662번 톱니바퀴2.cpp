#include <iostream>
#include <deque>

using namespace std;

deque<char> gear[1001];
int rotation[1001];
void Rotate(int index,int type)
{
	if (type == 1)
	{
		char tmp = gear[index].back();
		gear[index].pop_back();
		gear[index].push_front(tmp);
	}
	else if(type == -1)
	{
		char tmp = gear[index].front();
		gear[index].pop_front();
		gear[index].push_back(tmp);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		for(int j=0;j<8;j++)
		{
			char a;
			cin >> a;
			gear[i].push_back(a);
		}
	}
	int k;
	cin >> k;
	while (k--)
	{
		for (int i = 0; i < 1001; i++)rotation[i] = 0;
		int index,type;
		cin >> index >> type;
		rotation[index] = type;
		int curType = type;
		for (int i = index + 1; i <= t; i++)
		{
			curType *= -1;
			if (gear[i - 1][2] != gear[i][6])
				rotation[i] = curType;
			else break;
				
		}
		curType = type;
		for (int i = index - 1; i > 0; i--)
		{
			curType *= -1;
			if (gear[i + 1][6] != gear[i][2])
				rotation[i] = curType;
			else break;
		}
		for (int i = 1; i <= t; i++)
		{
			Rotate(i, rotation[i]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= t; i++)
	{
		if (gear[i].front() == '1')ans++;
	}
	cout << ans;
}