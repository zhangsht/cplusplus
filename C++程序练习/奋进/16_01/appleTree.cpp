//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <queue>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

struct node {
	int amount;
	std::vector<int> v;
};
int ans, step;
node s[101];
bool visited[101];
queue<node> q;

void bfs(int u) {
	visited[u] = true;
	q.push_back(s[u]);
	node b = q.front();
	q.pop();
	while (!q.empty()) {
	    
	}
}

int main() {
	int n, k;
	while (cin >> n) {
		q.clear();
	    cin >> s[1].step;
	    ans = 0;
	    memset(visited, 0, sizeof(visited));
	    for (int i = 1; i <= n; ++i) {
	    	cin >> s[i].amount;
	    }
	    int u, v;
	    for (int i = 1; i < n; ++i) {
	    	cin >> u >> v;
	    	amount[u].v.push_back(v);
	    }

	    bfs(1);
	    cout << ans << endl;
	}
	return 0;
}
