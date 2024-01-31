#include <cstdio>
#include <deque>

using namespace std;

int main() {
	deque<int> dq;
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		dq.push_back(i + 1);
	}
	while (dq.size() != 1) {
		dq.pop_front();
		int n = dq.at(0);
		dq.push_back(n);
		dq.pop_front();
	}
	printf("%d", dq.at(0));
}