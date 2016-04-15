#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int temp;
	priority_queue<int, vector<int>, greater<int> > l;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		l.push(temp);
	}

	while (!l.empty()) {
		printf("%d\n", l.top());
		l.pop();
	}

}
