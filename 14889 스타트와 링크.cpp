#include <iostream>
#include <vector>
using namespace std;

int s[20][20];
int n;
int minValue = 999999;
bool isChecked[20];
int maxValue = 0;
int Abs(int a)
{
    if (a < 0)return -a;
    return a;
}
int GetStatValue(vector<int> humans)
{
    int value = 0;
    for (int i = 0; i < humans.size(); i++)
    {
        for (int j = 0; j < humans.size(); j++)
        {
            value += s[humans[i]][humans[j]];
        }
    }
    int leftValue = maxValue - value;
    return abs(leftValue - value);
}
void MakePair(int startIndex, int size)
{
    if (size == n / 2)
    {
        vector<int> startTeam;
        for (int i = 0; i < n; i++)
        {
            if (isChecked[i])startTeam.push_back(i);
        }
        minValue = min(minValue, GetStatValue(startTeam));
        return;
    }
    for (int i = startIndex; i < n; i++)
    {
        isChecked[i] = true;
        MakePair(i + 1, size + 1);
        isChecked[i] = false;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
            maxValue += s[i][j];
        }
    }
    MakePair(0, 0);
    cout << minValue;
}