#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int> > mp;
vector<vector<bool> > visit;

struct node {
  int x, y;
  int len;
  node(int j, int b, int l) : x(j), y(b), len(l) {}

};

bool isout(int x, int y) {
  return (x < 0 || x >= n || y < 0 || y >= n);
}

int bfs() {
  queue<node> buf;
  buf.push(node(0, 0, 1));
  visit[0][0] = true;
  int ans = 0;
  int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  while (!buf.empty()) {
    node now = buf.front();
    buf.pop();

    if (now.x == n-1 && now.y == n-1) {
      ans = now.len;
      break;
    }
    for (int i = 0; i < 4; ++i) {
      int x = now.x + go[i][0];
      int y = now.y + go[i][1];
      if ( !isout(x, y) && !visit[x][y] && !mp[x][y]) {
        buf.push(node(x, y, now.len+1));
        visit[x][y] = true;
      }
    }
  }

  return ans;
}
int main() {

  while(cin >>n && n) {
    mp.assign(n, vector<int>(n, 0));
    visit.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> mp[i][j];
      }
    }

    cout << bfs() << endl;
  }
}
