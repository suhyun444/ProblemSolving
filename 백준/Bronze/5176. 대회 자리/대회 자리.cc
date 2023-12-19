#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {


	int t;
	cin >> t;
	while (t--)
	{
		int p , m ;
		cin >> p >> m;
		bool seat[501] = {};
		int result = 0;
		for (int i = 0; i < p; ++i)
		{
			int cur;
			cin >> cur;
			if (seat[cur])
			{
				++result;
			}
			seat[cur] = true;
		}
		cout << result << "\n";
	}

}