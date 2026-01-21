#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;


vector<long long> arr;
bool compare(long long a,long long b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),compare);
    long long sum = 0;
    for(int i=0;i<n;++i)
    {
        if((i + 1) % 3 != 0)
        {
            sum += arr[i];
        }
    }
    cout << sum;
}