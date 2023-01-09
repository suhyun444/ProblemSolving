#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)return a;
    else return gcd(b, a % b);
}
long long mul(long long num, long long count)
{
	if (count == 1)return num;
	if (count & 1)return num * mul(num, count - 1) % 1000000007;
	long long ret = mul(num, count / 2);
	return (ret * ret) % 1000000007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long  ret = 0;
    int m,n,s;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> n >> s;
        long long gcdNum = gcd(n, s);
        s /= gcdNum;
        n /= gcdNum;
        long long inv = mul(n, 1000000005);
        ret += s * inv % 1000000007;
        ret %= 1000000007;
    };
    cout << ret;
}