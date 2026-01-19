#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int n;
int cur = 0;
vector<int> pre;
vector<int> in;
void initTree(int l,int r)
{
    if(l == r) return;
    int current = pre[cur++];
    for(int i=l;i<r;++i)
    {
        if(in[i] == current)
        {
            initTree(l,i);
            initTree(i + 1,r);
        }
    }
    cout << current<<" ";
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
        cin >> n;
        int item = 0;
        for(int i=0;i<n;++i)
        {
            cin >> item;
            pre.push_back(item);
        }
        for(int i=0;i<n;++i)
        {
            cin >> item;
            in.push_back(item);
        }
        initTree(0,n);
        cout << "\n";
        cur = 0;
        pre.clear();
        in.clear();
    }
}