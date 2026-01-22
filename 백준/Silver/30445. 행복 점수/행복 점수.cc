#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;


int happyScore[26];
int sadScore[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    happyScore['H' - 'A'] = 1;
    happyScore['A' - 'A'] = 1;
    happyScore['P' - 'A'] = 1;
    happyScore['Y' - 'A'] = 1;
    sadScore['S' - 'A'] = 1;
    sadScore['A' - 'A'] = 1;
    sadScore['D' - 'A'] = 1;
    string s;
    getline(cin,s);
    cout << fixed;
    cout.precision(2);
    int happy = 0;
    int sad = 0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i] ==' ')continue;
        happy += happyScore[s[i] - 'A'];
        sad += sadScore[s[i] - 'A'];
    }
    if(happy == 0 && sad == 0)
    {
        cout << "50.00";
        return 0;
    }
    float result = (float)happy / ((float)happy + (float)sad);
    result *= 10000;
    result = round(result);
    result /= 100;
    cout << result;

}