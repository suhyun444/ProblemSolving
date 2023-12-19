#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cur = 1;
    int type = 1;
    while (true)
    {
        if (n < cur)
        {
            if (type == 1)
            {
                cout << cur - n << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
            break;
        }
        n -= cur;
        type *= -1;
        cur++;
    }
}