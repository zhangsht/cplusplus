#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 201;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int n, m;
bool ans;

void init() {
	ans = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			map[i][j] = -1;
		map[i][i] = 0;
		visited[i] = false;
	}
}

void bfs(int s) {
	visited[s] = true;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		for (int i = 0; i < n; i++) {
			if (map[u][i] > 0 && !visited[i]) {
				if (i == n - 1) {
					ans = true;
					break;
				}
				visited[i] = true;
				q.push(i);
			}
		}
		q.pop();
	}
}

int main() {
	while (cin >> n && n) {
		init();
		cin >> m;
		int u, v;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			map[u][v] = 1;
		}
		bfs(0);
		if (ans) cout << "I can post the letter\n";
		else cout << "I can't post the letter\n";
	}
	return 0;
}