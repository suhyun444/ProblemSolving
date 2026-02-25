#include <iostream>

using namespace std;

long long dp[101];
int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        for(int j = 3;j<i;++j)
        {
            dp[i] = max(dp[i],dp[i-j] * (j-1));
        }
    }
    cout << dp[n];
}