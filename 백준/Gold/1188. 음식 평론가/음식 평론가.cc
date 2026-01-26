#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int gcd(int a,int b)
{
    if(b == 0)return a;
    return gcd(b,a % b);
}
int diff[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    cout << m - gcd(n,m);

}