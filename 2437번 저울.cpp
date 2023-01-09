#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());
    int result = 1;
    for (int i = 0; i < n; i++) {
        if (result < weight[i]) {
            break;
        }
        result += weight[i];
    }
    cout << result;
}