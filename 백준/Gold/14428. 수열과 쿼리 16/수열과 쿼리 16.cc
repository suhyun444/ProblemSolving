#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n;
int arr[100001];
int tree[300001];
void initTree(int n,int l,int r)
{
    if(l==r)
    {
        tree[n] = l;
        return;
    }
    int mid = (l+r) /2;
    initTree(n*2,l,mid);
    initTree(n*2 + 1,mid + 1,r);
    tree[n] = ((arr[tree[n*2]] <= arr[tree[n*2+1]])?tree[n*2]:tree[n*2+1]);
}
int query(int l,int r,int n,int nodeL,int nodeR)
{
    if(r < nodeL || nodeR < l)return -1;
    if(nodeL <= l && r <= nodeR)return tree[n];
    int mid = (l + r) / 2;
    int left = query(l,mid,n*2,nodeL,nodeR);
    int right = query(mid + 1,r,n*2 + 1,nodeL,nodeR);
    if(left == -1)return right;
    else if(right == -1)return left;
    return ((arr[left] <= arr[right])? left : right);
}
void update(int l,int r,int n,int index)
{
    if(index < l || r < index)return;
    if(l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    update(l,mid,n*2,index);
    update(mid + 1,r,n*2+1,index);
    tree[n] = (arr[tree[n*2]] <= arr[tree[n*2+1]])?tree[n*2]:tree[n*2+1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> arr[i];
    }
    int t;
    cin >> t;
    initTree(1,1,n);
    for(int i=0;i<t;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1)
        {
            arr[b] = c;
            update(1,n,1,b);
        }
        else
        {
            cout << query(1,n,1,b,c) << "\n";
        }
    }
}
