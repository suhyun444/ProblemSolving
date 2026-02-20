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
    int n,l,m;
    cin >> n >> l >> m;
    vector<pair<int,int>> fish;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin >> y >> x;
        fish.push_back({y,x});
    }
    int ans = 0;
    for(int i=0;i<fish.size();++i)
    {
        pair<int,int> cur = fish[i];
        for(int j=1;j<l/2;++j)
        {
            int row = j;
            int col = l / 2 - row;
            for(int offset = 0;offset <= col;++offset)
            {
                int sy = cur.first;
                int sx = cur.second - offset;
                if(sy + row > n + 1  || sx + col > n  || sx < 1 || sy < 1)continue;
                int count = 0;
                for(int k=0;k<fish.size();++k)
                {
                    pair<int,int> next = fish[k];
                    if(sy <= next.first && next.first <= sy + row && sx <= next.second && next.second <= sx + col)
                    {
                        count++;
                    }
                }
                ans = max(ans,count);
            }
        }
    }
    cout << ans;
}
