#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int mainX, mainY;
vector<pair<int, int>> points;
bool Compare(const pair<int,int>& p1, const pair<int,int>& p2)
{
    int ap = p1.second - mainX, aq = p1.first- mainY, bp = p2.second - mainX, bq = p2.first- mainY;
    if (1LL * aq * bp != 1LL * ap * bq) return 1LL * aq * bp < 1LL * ap * bq;
    if (p1.first == p2.first) return p1.second< p2.second;
    return p1.first< p2.first;
}
long long CCW(const pair<int, int>& p1, const pair<int, int>& p2, const pair<int, int>& p3)
{
    return 1LL * (p2.second - p1.second) * (p3.first- p1.first) - 1LL * (p2.first- p1.first) * (p3.second- p1.second);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        points[i] = { b,a };
    }
    sort(points.begin(), points.end());
    mainX = points[0].second;
    mainY = points[0].first;
    sort(points.begin() + 1, points.end(), Compare);
    stack<int> s;
    s.push(0);
    s.push(1);
    for (int i = 2; i < n; ++i)
    {
        while (s.size() >= 2)
        {
            int p1 = s.top();
            s.pop();
            int p2 = s.top();
            if (CCW(points[p2], points[p1], points[i]) > 0)
            {
                s.push(p1);
                break;
            }
        }
        s.push(i);
    }
    cout << s.size();
}