#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<string, bool> m;
	int n;
	int k, maxNum = -1;
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	while (k--) {
		int size = q.size();
		m.clear();
		while (size--) {
			int cur = q.front();
			string curString = to_string(cur);
			q.pop();
			for (int i = 0; i < curString.length() -1; i++) {
				for (int j = i + 1; j < curString.length(); j++) {
					string tmpString = curString;
					char tmp = tmpString[i];
					tmpString[i] = tmpString[j];
					tmpString[j] = tmp;
					if (tmpString[0] != '0' && m.find(tmpString) == m.end()) {
						q.push(stoi(tmpString));
						m.insert({ tmpString,true });
					}
				}
			}
		}
		if (k == 0) {
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				maxNum = max(maxNum, cur);
			}
		}
	}
	cout << maxNum;
}