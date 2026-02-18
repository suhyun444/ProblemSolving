#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string ans = "";
    for(int i=0;i<s.size();)
    {
        if(s[i] == 'K')
        {
            ans += "5";
            ++i;
        }
        if(s[i] == 'M')
        {
            int cur = i;
            ++i;
            while(i < s.size() - 1 && s[i] == 'M')
                ++i;
            if(i == s.size() || s[i] == 'M')
            {
                for (int j = cur; j < i; ++j)
                {
                    ans += "1";
                }
            }
            else
            {
                ans +=  "5";
                for(int j=0;j<i-cur;++j)
                {
                    ans += "0";
                }
                ++i;
            }
        }
    }
    cout << ans << "\n";
    ans = "";
    for(int i=0;i<s.size();)
    {
        if(s[i] == 'K')
        {
            ans += "5";
            ++i;
        }
        else
        {
            int cur = i;
            while(i < s.size() && s[i] == 'M')
                ++i;
            ans += "1";
            for(int j=0;j<i-cur-1;++j)
            {
                ans += "0";
            }
        }
    }
    cout << ans ;
}
