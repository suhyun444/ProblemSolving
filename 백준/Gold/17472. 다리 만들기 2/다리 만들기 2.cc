#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int curArea = 1;
int board[11][11];
bool visited[11][11];
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
struct Edge
{
	int u, v, w;
	Edge(int u, int v, int w) : u{ u }, v{ v }, w{ w } {}
};
vector<Edge> edges;
int p[7];
int Find(int cur)
{
	if (p[cur] < 0)return cur;
	return p[cur] = Find(p[cur]);
}
bool Merge(int a,int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b)
	{
		p[b] = a;
		return true;
	}
	return false;
}
bool Compare(const Edge& e1, const Edge& e2)
{
	return e1.w < e2.w;
}
void dfs(int curY,int curX)
{
	board[curY][curX] = curArea;
	visited[curY][curX] = true;
	for (int i = 0; i < 4; i++)
	{
		int nextY = curY + dirY[i];
		int nextX = curX + dirX[i];
		if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
		{
			if (!visited[nextY][nextX] && board[nextY][nextX] == 1)
			{
				dfs(nextY, nextX);
			}
		}
	}
}
void dfsAll()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && board[i][j] == 1)
			{
				dfs(i, j);
				curArea++;
			}
		}
	}
}
void MakeBridge(int curY ,int curX ,int direction)
{
	int startArea = board[curY][curX];
	int dist = 0;
	while (true)
	{
		dist++;
		curY += dirY[direction];
		curX += dirX[direction];
		if (curY < 0 || curX < 0 || curY >= n || curX >= m) return;
		if (board[curY][curX] == startArea) return;
		if (board[curY][curX] != 0)
		{
			if (dist <= 2)return;
			edges.push_back(Edge(startArea, board[curY][curX], dist - 1));
			return;
		}
	}
}
void FindAllBridge()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				MakeBridge(i, j, k);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(p, -1, sizeof(p));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	dfsAll();
	FindAllBridge();
	int count = 0;
	int ans = 0;

	sort(edges.begin(), edges.end(), Compare);
	for(int i=0;i<edges.size();i++)
	{
		if (Merge(edges[i].u, edges[i].v))
		{
			ans += edges[i].w;
			count++;
			if (count == curArea - 2)
			{
				cout << ans;
				return 0;
			}
		}
	}
	cout << "-1";
}