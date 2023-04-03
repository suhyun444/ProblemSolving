#include <iostream>

using namespace std;

int n, s, val[20], sum = 0, cnt = 0;
void dfs(int current) {
    if (current == n) {
        return;
    }
    if (sum + val[current]== s) {
        cnt++;
    }
    dfs(current + 1);
    sum += val[current];
    dfs(current + 1);
    sum -= val[current];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 0;i < n;i++) {
        cin >> val[i];
    }
    dfs(0);
    cout << cnt;
}