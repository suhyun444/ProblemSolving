#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <stack>

using namespace std;


int arr[100001];
int tree[300001];
int initTree(int n,int l,int r)
{
    if(l==r)
    {
       return tree[n] = arr[l];
    }
    int mid = (l + r) / 2;
    return tree[n] = min(initTree(n*2,l,mid),initTree(n*2+1,mid + 1,r)); 
}
int query(int n,int l,int r,int nodeL,int nodeR)
{
    if(r < nodeL || nodeR < l) return 2e9;
    if(nodeL <= l && r <= nodeR) return tree[n];
    int mid = (l+r) / 2;
    return min(query(n*2,l,mid,nodeL,nodeR),query(n*2+1,mid+1,r,nodeL,nodeR));
}
int update(int n,int l,int r,int index)
{
    if(r < index || l > index)return tree[n];
    if(l == r)
        return tree[n] = arr[l];
    int mid = (l + r) / 2;
    return tree[n] = min(update(n*2,l,mid,index),update(n*2+1,mid + 1,r,index)); 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> arr[i];
    }
    initTree(1,1,n);
    int m;
    cin >> m;
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1)
        {
            arr[b] = c;
            update(1,1,n,b);
        }
        else
        {
            cout << query(1,1,n,b,c) << "\n";
        }
    }
}
