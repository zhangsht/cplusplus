#include <cstdio>

int next[500100],
	pre[500100];

int main() {
	int test, n, m;
	int mode, a, b;
	int link, i;

	scanf("%d", &test);
	while(test--) {
		scanf("%d%d", &n, &m);

		for(i = 1; i <= n + 1; ++i) {
			next[i - 1] = i;
			pre[i] = i - 1;
		}
		for(i = 0; i < m; ++i) {
			scanf("%d%d%d", &mode, &a, &b);
				if (mode == 1) {
					next[pre[a]] = next[a];
					pre[next[a]] = pre[a];

					next[pre[b]] = a;
					pre[a] = pre[b];

					next[a] = b;
					pre[b] = a;
				} else {
					next[pre[a]] = next[a];
					pre[next[a]] = pre[a];

					pre[next[b]] = a;
					next[a] = next[b];

					pre[a] = b;
					next[b] = a;
				}
			}

		link = 0;
		for(i = 0; i < n; ++i) {
			printf("%d ", next[link]);
			link = next[link];
		}
		printf("\n");
 }
	return 0;
}
