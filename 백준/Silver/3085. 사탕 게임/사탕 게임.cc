#include <iostream>
#include <algorithm>

using namespace std;

string board[50];
int check(int max,int n) {
    int count = 1;
    for (int i = 0;i < n;i++) {
        count = 1;
        for (int j = 0;j < n-1;j++) {
            if (board[i][j] == board[i][j + 1]) {
                count++;
                if (max < count) {
                    max = count;
                }
            }
            else if (board[i][j] != board[i][j + 1]) {
                count = 1;
            }
        }
    }
    for (int i = 0;i < n;i++) {
        count = 1;
        for (int j = 0;j < n-1;j++) {
            if (board[j][i] == board[j+1][i]) {
                count++;
                if (max < count) {
                    max = count;
                }
            }
            else if (board[j][i] != board[j + 1][i]) {
                count = 1;
            }
        }
    }
    return max;
}
int main()
{
    int n,result = 0;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> board[i];
    }
    for (int i = 0;i < n - 1;i++) {
        for (int j = 0;j < n - 1;j++) {
            swap(board[i][j], board[i][j + 1]);
            result = max(result, check(0, n));
            swap(board[i][j], board[i][j + 1]);

            swap(board[i][j], board[i + 1][j]);
            result = max(result, check(0, n));
            swap(board[i][j], board[i + 1][j]);
        }
    }
    swap(board[n - 1][n - 1], board[n - 2][n - 1]);
    result - max(result, check(0, n));
    swap(board[n - 1][n - 1], board[n - 2][n - 1]);

    swap(board[n - 1][n - 1], board[n - 1][n - 2]);
    result = max(result, check(0, n));
    swap(board[n - 1][n - 1], board[n - 1][n - 2]);
    cout << result;
}