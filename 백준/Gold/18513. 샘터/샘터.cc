#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    queue<pair<int,pair<int,int>>> q;
    set<int> satis;
    for(int i=0;i<n;++i)
    {
        int a;
        cin >> a;
        q.push({a,{-1,0}});
        q.push({a,{1,0}});
        satis.insert(a);
    }
    long long ans = 0;
    while(k > 0)
    {
        pair<int,pair<int,int>> cur = q.front();
        q.pop();
        cur.first += cur.second.first;
        cur.second.second += 1;
        if(satis.find(cur.first) == satis.end())
        {
            satis.insert(cur.first);
            ans += 1L * cur.second.second;
            q.push(cur);
            if(--k == 0)
            {
                cout << ans;
                return 0;
            }
        }
    }
}
