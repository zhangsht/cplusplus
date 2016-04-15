#include <cstdio>
#include <stack>

using namespace std;

int array[200010];

int main() {
	int n, h, w, i;
	while (scanf("%d", &n) && n) {
		for (i = 1; i <= n; i++) {
			scanf("%d%d", &h, &w);
			array[h] = array[w] = i;
		}
		stack<int> circle;
		for (i = 2 * n; i >= 1; i--) {
			if (circle.empty()) circle.push(array[i]);
			else if (circle.top() == array[i]) {
				circle.pop();
			} else {
				circle.push(array[i]);
			}
		}
		if (circle.empty()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
