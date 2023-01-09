#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
#include <map>
#include <bitset>
int GetFx(int n, bool* arr)
{
    if (n > 10000 || n == 0)
    {
        return 0;
    }
    int sum = n;
    while (true)
    {
        if (n == 0)
        {
            break;
        }
        sum += n % 10;
        n /= 10;
    }
    if (sum < 10000)
        arr[sum] = false;
    return GetFx(sum, arr);
}
int main()
{

    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool n[10000];
    for (int i = 0; i < 10000; ++i)
    {
        n[i] = true;
    }
    for (int i = 1; i < 10000; ++i)
    {
        if (n[i] != false)
        {
            GetFx(i, n);
        }
    }
    for (int i = 1; i < 9994; ++i)
    {
        if (n[i] == true)
        {
            cout << i << "\n";
        }
    }
}