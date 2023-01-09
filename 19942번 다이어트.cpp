#include <iostream>
#include <vector>

using namespace std;
struct food
{
    int p;
    int f;
    int s;
    int v;
    int cost;
};
int n;
int mp, mf, ms, mv, mc = 2e9;
vector<food> foods;
vector<int> curChoice;
vector<int> bestChoice;
void solve(int startIndex, int p, int f, int s,int v, int c)
{
    if (p >= mp && f >= mf && s >= ms && v >= mv)
    {
        if (mc > c)
        {
            mc = c;
            bestChoice = curChoice;
        }
        return;
    }
    for (int i = startIndex; i < n; i++)
    {
        curChoice.push_back(i);
        solve(i + 1, p + foods[i].p, f + foods[i].f, s + foods[i].s, v + foods[i].v, c + foods[i].cost);
        curChoice.pop_back();
    }
}
int main()
{
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
    {
        int p, f, s, v, c;
        cin >> p >> f >> s >> v >> c;
        food food;
        food.p = p;
        food.f = f;
        food.s = s;
        food.v = v;
        food.cost = c;
        foods.push_back(food);
    }
    solve(0, 0, 0, 0, 0, 0);
    if (mc == 2e9)
    {
        cout << "-1";
        return;
    }
    cout << mc << "\n";
    for (int cur : bestChoice)
    {
        cout << cur + 1 << " ";
    }

}