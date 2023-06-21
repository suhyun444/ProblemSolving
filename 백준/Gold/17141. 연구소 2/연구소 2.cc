#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 987654321

/*
7 6
2 0 2 0 1 1 0
0 0 1 0 1 2 0
0 1 1 2 1 0 0
2 1 0 0 0 0 2
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2
*/
using namespace std;

int cnt = 1;
int ret = INF;
int n;
int m;
int board[50][50];
int copyboard[50][50];
vector<pair<int, int>> virus;
vector<pair<int, int>> back;
int check[2][4] = {
	{0,1,0,-1},
	{1,0,-1,0}
};
int bfs() {
	queue<pair<int, int>> que;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (copyboard[i][j] == 3) {
				que.push(make_pair(i, j));
			}
		}
	}
	int level = 0;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			pair<int, int> cur = que.front();
			que.pop();
			for (int j = 0; j < 4; j++) {
				int dir_y = cur.first + check[0][j];
				int dir_x = cur.second + check[1][j];
				if (0 <= dir_y && dir_y < n && 0 <= dir_x && dir_x < n) {
					if (copyboard[dir_y][dir_x] == 0 || copyboard[dir_y][dir_x] == 2) {
						copyboard[dir_y][dir_x] = 3;
						que.push(make_pair(dir_y, dir_x));
					}
				}
			}
		}
		level++;
	}
	return level;
}
void backtracking(int index) {
	if (back.size() == m) {
		memcpy(copyboard, board, sizeof(board));
		for (int i = 0; i < virus.size(); i++)
		{
			copyboard[virus[i].first][virus[i].second] = 0;
		}
		for (int i = 0; i < back.size(); i++) {
			copyboard[back[i].first][back[i].second] = 3;
		}
		int result = bfs();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (copyboard[i][j] == 0) {
					result = -1;
				}
			}
		}
		if (result != -1) {
			ret = min(ret, result);
		}
		return;
	}
	for (int i = index; i < virus.size(); i++) {
		back.push_back(make_pair(virus[i].first, virus[i].second));
		backtracking(i + 1);
		back.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}
	backtracking(0);
	if (ret == INF) {
		cout << "-1";
		return 0;
	}
	cout << ret - 1;
	return 0;
}