#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1000001];
int solve(int n) {
    if (n == 1) {
        return 0;
    }
    int& ret = dp[n];
    if (ret != -1) {
        return ret;
    }
    int result = solve(n - 1) + 1;
    if (n % 3 == 0) {
        result = min(result, solve(n / 3) + 1);
    }
    if (n % 2 == 0) {
        result = min(result, solve(n / 2) + 1);
    }
    dp[n] = result;
    return result;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << solve(n); 
}