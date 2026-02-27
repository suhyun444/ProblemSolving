#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int dist(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1 - x2,2) + pow(y1-y2,2));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int sx,sy,ex,ey;
        cin >> sx>>sy>>ex>>ey;
        int n;
        cin >> n;
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            int x,y,r;
            cin >> x >> y >> r;
            if(dist(x,y,ex,ey) < r && dist(x,y,sx,sy) >= r)
            {
                ans++;       
            }
            else if(dist(x,y,ex,ey) >= r && dist(x,y,sx,sy) < r)
            {
                ans++;
            }
        }
        cout << ans<<"\n";
    }
}
