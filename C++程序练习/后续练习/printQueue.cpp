#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int weight;
	bool flag;
	node(int w, bool f) {
		weight = w;
		flag = f;
	}
};

int main() {
	int test;
	cin >> test;

	while(test--) {
		int n, m;
		priority_queue<int> pQ;
		queue<node> q;

		cin >> n >> m;
		for (int i = 0, temp; i < n; i++) {
			cin >> temp;
			if (i == m) q.push(node(temp, true));
			else q.push(node(temp, false));
			pQ.push(temp);
		}

		int tot = 0, cur;
		bool curFlag;
		while (!q.empty()) {
			cur = q.front().weight;
			curFlag = q.front().flag;
			if (cur == pQ.top()) {
				tot++;
				if (curFlag) break;
				else {
					q.pop();
					pQ.pop();
				}
			} else {
				q.push(q.front());
				q.pop();
			}
		}

		// for (int i = 0; i <= m; i++) {
		// 	if (q.front() == pQ.top()) {
		// 		q.pop();
		// 		pQ.pop();
		// 		tot++;
		// 		if (i == m) break;
		// 	} else {
		// 		q.push(q.front());
		// 		q.pop();
		// 		if (i == m) m = q.size() - 1;
		// 	}
		// }
		cout << tot << endl;
	}
	return 0;
}