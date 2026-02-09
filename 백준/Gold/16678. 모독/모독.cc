#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

vector<int> arr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int item;
    for(int i=0;i<n;++i)
    {
        cin >> item;
        arr.push_back(item);
    }
    sort(arr.begin(),arr.end());
    int cur = 1;
    long long ans = 0;
    for(int i=0;i<n;++i)
    {
        if(arr[i] >= cur)
        {
            ans += 1LL * (arr[i] - cur);
            cur++;
        }
    }
    cout << ans;
}