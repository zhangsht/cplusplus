#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vertices[101];
int visited[101] = {0};
int ans = 0;
int n, m, u, v;

void bfs(int start) {
    visited[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int next = q.front();
        for (int i = vertices[next].size() - 1; i >= 0; i--) {
            if (!visited[vertices[next][i]]) {
                q.push(vertices[next][i]);
                visited[vertices[next][i]] = 1;
            }
        }
        q.pop();
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans++;
            bfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        vertices[u].push_back(v);
        vertices[v].push_back(u);
    }

    solve();
    cout << ans << endl;
    return 0;
}
