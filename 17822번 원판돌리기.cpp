#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

deque<int> dq[51];
int n, m, t;
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { 1,-1,0,0 };
void Rotate(int i, int type)
{
	if (type == 0)
	{
		int tmp = dq[i].back();
		dq[i].pop_back();
		dq[i].push_front(tmp);
	}
	else if (type == 1)
	{
		int tmp = dq[i].front();
		dq[i].pop_front();
		dq[i].push_back(tmp);
	}
}
void Func()
{
	bool isFind = false;
	bool isSame[51][51];
	memset(isSame, false, sizeof(isSame));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nextX = j + dirX[k];
				nextX %= m;
				int nextY = i + dirY[k];
				if (0 < nextY && nextY <= n && 0<= nextX)
				{
					if (dq[i][j] == dq[nextY][nextX] && dq[i][j] < 10000)
					{
						isFind = true;
						isSame[i][j] = isSame[nextY][nextX] = true;
					}
				}
			}
		}
	}
	if (isFind)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (isSame[i][j])
				{
					dq[i][j] = 1e9;
				}
			}
		}
	}
	else
	{
		float sum = 0;
		float cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (dq[i][j] < 10000)
				{
					sum += dq[i][j];
					cnt++;
				}
			}
		}
		if (cnt == 0)
			return;
		float average = sum / cnt;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (dq[i][j] > average)
				{
					dq[i][j] -= 1;
				}
				else if(dq[i][j] < average)
				{
					dq[i][j] += 1;
				}
			}
		}
	}
}
void Display()
{
	cout << "s\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0;j < m; j++)
		{
			if (dq[i][j] > 10000)
				cout << "x ";
			else
				cout << dq[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "e\n\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			dq[i].push_back(a);
		}
	}
	for (int i = 0; i < t; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		for (int i = x; i <= n; i += x)
		{
			for (int j = 0; j < k; j++)
			{
				Rotate(i, d);
			}
		}
		//Display();
		Func();
		//Display();
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dq[i][j] < 10000)sum += dq[i][j];
		}
	}
	cout << sum;
}