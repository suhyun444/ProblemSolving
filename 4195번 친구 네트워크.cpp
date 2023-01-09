#include <iostream>
#include <cstring>
#include <map>
#include <unordered_map>

using namespace std;

int p[200001];
int numOfGroup[200001];
unordered_map<string, int> nameToIndex;
int find(int cur)
{
	if (p[cur] < 0) return cur;
	return p[cur] = find(p[cur]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)return;
	numOfGroup[a] += numOfGroup[b];
	p[b] = a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int f;
		cin >> f;
		memset(p, -1, sizeof(p));
		for (int i = 0; i < 200001; i++)
			numOfGroup[i] = 1;
		int index = 0;
		for (int i = 0; i < f; i++)
		{
			string a, b;
			cin >> a >> b;
			if (nameToIndex.find(a) == nameToIndex.end())
				nameToIndex.insert({ a,index++}); 
			if (nameToIndex.find(b) == nameToIndex.end())
				nameToIndex.insert({ b, index++ });
			merge(nameToIndex[a], nameToIndex[b]);
			cout << numOfGroup[find(nameToIndex[a])] << "\n";
		}
		nameToIndex.clear();
	}
}