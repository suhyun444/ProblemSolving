#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Trie
{
public:
	map<string, Trie> node;
	void Insert(vector<string> name,int index)
	{
		if (name.size() == index)return;
		if (node.find(name[index]) == node.end())
		{
			node.insert({ name[index],Trie() });
			node[name[index]].Insert(name, index + 1);
			return;
		}
		else
		{
			node[name[index]].Insert(name,index + 1);

		}
	}
	void PreOrder(int depth)
	{
		if (node.empty())
		{
			return;
		}
		auto iter = node.begin();
		while (iter != node.end())
		{
			for (int i = 0; i < depth; ++i)cout << "--";
			cout << iter->first << "\n";
			iter->second.PreOrder(depth + 1);
			iter++;
		}
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Trie main = Trie();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		vector<string> names(m);
		for (int j = 0; j < m; ++j)
		{
			cin >> names[j];
		}
		main.Insert(names, 0);
	}
	main.PreOrder(0);
}