#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

typedef unsigned int lint;

priority_queue<lint> pq;

int main() {
    int i, n;
    lint val;
    cin >> n;
    int m = n / 2;
    for (i = 0; i <= m; i++) {
        cin >> val;
        pq.push(val);
    }
    for (; i < n; i++) {
        cin >> val;
        if (val < pq.top()) {
            pq.pop();
            pq.push(val);
        }
    }
    double ans = pq.top();
    if (n % 2 == 0) {
        pq.pop();
        ans += pq.top();
        ans /= 2;
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
