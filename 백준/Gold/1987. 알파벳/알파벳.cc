#include <iostream>
#include <algorithm>

using namespace std;

int r, c;
int result;
bool alpha[28] = { false };
char board[20][20];
int dir_y[4] = { 0,1,0,-1 };
int dir_x[4] = { 1,0,-1,0 };
void solve(int x, int y, int cnt) {
	result = max(result, cnt);
	for (int i = 0;i < 4;i++) {
		int nxt_x = x + dir_x[i];
		int nxt_y = y + dir_y[i];
		if (0 <= nxt_x && nxt_x < c && 0 <= nxt_y && nxt_y < r) {
			if (!alpha[board[nxt_y][nxt_x] - 'A']) {
				alpha[board[nxt_y][nxt_x] - 'A'] = true;
				solve(nxt_x, nxt_y, cnt + 1);
				alpha[board[nxt_y][nxt_x] - 'A'] = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cin >> board[i][j];
		}
	}
	alpha[board[0][0] - 'A'] = true;
	solve(0, 0, 1);
	cout << result;
}