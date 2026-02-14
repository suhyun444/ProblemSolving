#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int func(int cur)
{   
    int count = 0;
    for(int i=0;i<32;++i)
    {
        if((cur >> i) & 1)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    int ans = 0;
    while(func(n) > k)
    {
        for(int i=0;i<32;++i)
        {
            if((n >> i) & 1)
            {
                ans += 1<<i;
                n += 1<<i;
                break;
            }
        }
    }
    cout << ans;
}
