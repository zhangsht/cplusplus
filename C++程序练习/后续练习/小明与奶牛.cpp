#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, breed, outPut;
		cin >> n;
		priority_queue<int> q[4];
		for (int i = 0; i < n; i++) {
			cin >> breed >> outPut;
			q[breed].push(outPut);
		}
		for (int i = 1; i <= 3; i++) {
			if (!q[i].empty()) {
				cout << i << ' ' << q[i].top() << endl;
			}
		}
	}
	return 0;
}
