#include <iostream>
#include <cstring>

using namespace std;

int p[500001];
int find(int a) {
    if (p[a] == -1)return a;
    return p[a] = find(p[a]);
}
bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return false;
    }
    p[a] = b;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(p, -1, sizeof(p));
    int n, m,c1,c2;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        if (!merge(c1, c2)) {
            cout << i + 1;
            return 0;
        }
    }
    cout << "0";
}