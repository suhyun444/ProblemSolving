#include <iostream>
#include <queue>

using namespace std;

int n;
int playerValue[51][9];
bool visited[9];
vector<int> back;
int ans;
int CalculateValue()
{
	int cccc = 0;
	queue<int> player;
	int inning = 0, outCount = 0, score = 0, playerIndex = 0;
	while (inning < n)
	{
		int curValue = playerValue[inning][back[playerIndex]];
		if (curValue == 0)
		{
			if (++outCount == 3)
			{
				outCount = 0;
				while (!player.empty())player.pop();
				inning++;
			}
		}
		else
		{
			player.push(0);
			int size = player.size();
			while (size--)
			{
				int cur = player.front();
				player.pop();
				if (cur + curValue > 3)
					score++;
				else
					player.push(cur + curValue);
			}
		}
		playerIndex++;
		playerIndex %= 9;
	}
	return score;
}
void solve(int length)
{
	if (length == 9)
	{
		ans = max(ans, CalculateValue());
		return;
	}
	if (length == 3)
	{
		back.push_back(0);
		solve(length + 1);
		back.pop_back();
	}
	else
	{
		for (int i = 1; i < 9; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				back.push_back(i);
				solve(length + 1);
				back.pop_back();
				visited[i] = false;
			}
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> playerValue[i][j];
		}
	}
	solve(0);
	cout << ans;
}
