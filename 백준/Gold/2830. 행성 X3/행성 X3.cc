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
    for(int i=0;i<n;++i)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    long long ret = 0;
    for(int i=0;i<=20;++i)
    {
        long long one = 0;
        for(int j=0;j<n;++j)
        {
            if((arr[j] >> i)&1)
            {
                one++;
            }
        }
        long long zero = n - one;
        ret += zero * one * (1LL << i);
    }
    cout << ret;
}