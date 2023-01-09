#include<iostream>

using namespace std;

int main()
{
    int px[3], py[3];
    for (int i = 0; i < 3; i++)cin >> px[i] >> py[i];
    int s = px[0] * py[1] + px[1] * py[2] + px[2] * py[0];
    s = s - py[0] * px[1] - py[1] * px[2] - py[2] * px[0];
    if (s < 0)cout << "-1";
    else if (s == 0)cout << "0";
    else if (s > 0) cout << "1";
}