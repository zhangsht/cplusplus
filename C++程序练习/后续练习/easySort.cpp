#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T, n, data;
	cin >> T;
	while (T--) {
		cin >> n;
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 0; i < n; i++) {
			cin >> data;
			q.push(data);
		}
		for (int i = 0; i < n; i++) {
			cout << q.top() << endl;
			q.pop();
		}
	}
	return 0;
}