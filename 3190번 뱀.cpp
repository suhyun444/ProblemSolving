#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[101][101];
pair<int, int> GetXYDirection(int type)
{
	//y,x
	pair<int, int> d;
	switch (type)
	{
	case 0:
		d = { 0,1 };
		break;
	case 1:
		d = { 1,0 };
		break;
	case 2:
		d = { 0,-1 };
		break;
	case 3:
		d = { -1,0 };
		break;
	default:
		break;
	}
	return d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, l;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}
	vector<pair<int,char>> direction;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x;
		char a;
		cin >> x >> a;
		direction.push_back({ x,a });
	}
	pair<int, int> head;
	queue<pair<int, int>> snake;
	snake.push({ 1,1 });
	head = { 1,1 };
	board[1][1] = 2;
	int count = 1;
	int directionIndex = 0;
	int curDirection = 0;
	/*
	* 오른쪽 - 0
	* 아래쪽 - 1
	* 왼쪽 - 2
	* 위쪽 - 3
	*/
	while (true)
	{
		pair<int, int> dir = GetXYDirection(curDirection);
		int nextX = head.second + dir.second;
		int nextY = head.first + dir.first;
		if (nextX <= 0 || nextX > n || nextY <= 0 || nextY > n) break;
		if (board[nextY][nextX] == 2) break;
		if (board[nextY][nextX] == 1)
		{
			snake.push({ nextY,nextX });
			head = { nextY,nextX };
			board[nextY][nextX] = 2;
		}
		else if (board[nextY][nextX] == 0)
		{
			snake.push({ nextY,nextX });
			head = { nextY,nextX };
			board[nextY][nextX] = 2;

			pair<int, int> tail = snake.front();
			snake.pop();
			board[tail.first][tail.second] = 0;
		}
		for (int i = directionIndex; i < l; i++)
		{
			if (count == direction[i].first)
			{
				if (direction[i].second == 'L')
				{
					curDirection--;
					if (curDirection == -1)curDirection = 3;
				}
				else if (direction[i].second == 'D')
				{
					curDirection++;
					curDirection %= 4;
				}
				directionIndex++;
				break;
			}
		}
		count++;
	}
	cout << count;
}
