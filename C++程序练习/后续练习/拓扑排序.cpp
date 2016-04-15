#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10001;

int main() {
    int inDegree[MAX] = {0}, cost[MAX] = {0};
    vector<int> node[MAX];
    queue<int> q;
    int n, m;
    int u, v;
    int ans = 0, sorted = 0;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        node[v].push_back(u);
        inDegree[u]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!inDegree[i]) {
            cost[i] = 100;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        sorted++;
        ans += cost[head];
        for (int i = node[head].size() - 1; i >= 0; i--) {
            if (--inDegree[node[head][i]] == 0) q.push(node[head][i]);
            cost[node[head][i]] = cost[head] + 1;
        }
    }

    if (sorted == n) printf("%d\n", ans);
    else printf("Poor Xed\n");
    return 0;
}
