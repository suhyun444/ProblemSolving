#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, c;
bool visited[201][201][201];
vector<int> answer;
queue<pair<pair<int, int>, int>> q;
void MoveTo(int newA, int newB, int newC)
{
	if (!visited[newA][newB][newC])
	{
		q.push({ {newA,newB},newC });
		visited[newA][newB][newC] = true;
	}
}
void Bfs()
{
	q.push({ {0,0},c });
	visited[0][0][c];
	while (!q.empty())
	{
		pair<pair<int, int>, int> cur = q.front();
		q.pop();
		if (cur.first.first == 0)answer.push_back(cur.second);
		if (cur.first.first != 0)
		{
			int canCarryToB = b - cur.first.second;
			canCarryToB = min(canCarryToB, cur.first.first);
			MoveTo(cur.first.first - canCarryToB,cur.first.second + canCarryToB, cur.second);
			int canCarryToC = c - cur.second;
			canCarryToC = min(canCarryToC, cur.first.first);
			MoveTo(cur.first.first - canCarryToC, cur.first.second, cur.second + canCarryToC);
		}
		if (cur.first.second != 0)
		{
			int canCarryToA = a - cur.first.first;
			canCarryToA = min(canCarryToA, cur.first.second);
			MoveTo(cur.first.first + canCarryToA, cur.first.second - canCarryToA, cur.second);
			int canCarryToC = c - cur.second;
			canCarryToC = min(canCarryToC, cur.first.second);
			MoveTo(cur.first.first, cur.first.second - canCarryToC, cur.second + canCarryToC);
		}
		if (cur.second != 0)
		{
			int canCarryToA = a - cur.first.first;
			canCarryToA = min(canCarryToA, cur.second);
			MoveTo(cur.first.first + canCarryToA, cur.first.second, cur.second - canCarryToA);
			int canCarryToB = b - cur.first.second;
			canCarryToB = min(canCarryToB, cur.second);
			MoveTo(cur.first.first, cur.first.second + canCarryToB, cur.second - canCarryToB);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c;
	Bfs();
	int lastIndex = unique(answer.begin(), answer.end()) - answer.begin();
	sort(answer.begin(), answer.begin() + lastIndex);
	for (int i = 0; i < lastIndex - 1; i++)
	{
		cout << answer[i] << " ";
	}
}