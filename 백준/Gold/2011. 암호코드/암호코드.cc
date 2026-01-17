#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string s;
int cache[5001];
int dp(int current)
{
    if(current == s.length())
        return 1;
    if(s[current] == '0') 
        return 0;
    int& ret = cache[current];
    if(ret != -1)
        return ret;
    ret = dp(current + 1);
    ret %= 1000000;
    if(current + 1 != s.length() &&
    (( s[current] <= '2' && s[current + 1] <= '6') || 
    (s[current] <= '1' && s[current + 1] <= '9')))
    {
        ret += dp(current + 2);
        ret %= 1000000;
    }
    return ret % 1000000;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin >> s;
    int result = dp(0);
    cout << dp(0);
}