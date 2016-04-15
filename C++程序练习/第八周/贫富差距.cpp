#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t, n, k, tem;

    scanf("%d", &t);
    while (t--) {
        vector<int> v;
        scanf("%d%d", &n, &k);

        for (int i = 0; i < n; i++) {
            scanf("%d", &tem);
            v.push_back(tem);
        }
        sort(v.begin(), v.end());

        if (k % 2) {
            tem = k / 2;
            printf("%d\n", -v[tem] + v[n - 1 - tem]);
        } else {
            tem = k / 2;
            printf("%d\n", -(v[tem] + v[tem - 1]) / 2 + (v[n - 1 - tem] + v[n - tem]) / 2);
        }
    }
    return 0;
}

