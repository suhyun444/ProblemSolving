#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    while(true)
    {
        cin >> a >> b;
        if(a == 0 && b == 0)return 0;
        cout << ((a > b)?"Yes":"No") << "\n";
    }
}