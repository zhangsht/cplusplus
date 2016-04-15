#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int N = 10001;

int n, m;
bool visited[N];
int cost[N];
vector<int> node[N];
int u, v;
char tmp;
int depend;
int ans;

void dfs(int s) {
	visited[s] = true;
	ans += cost[s];

	int len = node[s].size();
	for (int i = 0; i < len; i++) {
		if (!visited[node[s][i]])
			dfs(node[s][i]);
	}
}

int main() {
	while (scanf("%d", &n) && n) {
		scanf("%d", &m);
		int i;
		for (i = 1; i <= n; i++) {
			node[i].clear();
			scanf("%d", &cost[i]);
			tmp = getchar();
			if (tmp == '\n') continue;

			while (true) {
				scanf("%d", &depend);
				node[i].push_back(depend);
				tmp = getchar();
				if (tmp == '\n') break;
			}
		}
		ans = 0;
		memset(visited, 0, sizeof(visited));
		dfs(m);
		printf("%d\n", ans);
	}
	return 0;
}
