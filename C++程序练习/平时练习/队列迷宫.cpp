#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <memory>
using namespace std;
int n;
struct coord {
    int x, y, count;
    bool range() {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
} start, end;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool mymap[35][35];
bool is_visited[35][35];

void bfs() {
    queue<coord> road;
    coord tem, curr;
    road.push(start);
    is_visited[0][0] = true;
    while (!road.empty()) {
        tem = road.front();
        if (tem.x == n - 1 && tem.y == n - 1) {
            cout << tem.count + 1 << endl;
            return;
        }
        road.pop();
        for (int i = 0; i < 4; i++) {
            curr.x = tem.x + d[i][0];
            curr.y = tem.y + d[i][1];
            curr.count = tem.count + 1;
            if (curr.range() && !is_visited[curr.x][curr.y] &&
              mymap[curr.x][curr.y]) {
                is_visited[curr.x][curr.y] = true;
                road.push(curr);
            }
        }
    }
    cout << "0\n";
}
int main() {
    while (cin >> n && n) {
        cin >> n;
    start.x = 0;
    start.y = 0;
    mymap[0][0] = true;
    end.x = 0;
    end.y = 0;
    mymap[0][0] = true;
    memset(mymap, false, sizeof(mymap));
    memset(is_visited, false, sizeof(is_visited));
    int tem;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tem;
            if (tem == 0) {
                mymap[i][j] = true;
            }
        }
    }
    bfs();
    }
    return 0;
}
