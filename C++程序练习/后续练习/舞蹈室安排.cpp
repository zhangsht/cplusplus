#include <iostream>
#include <algorithm>
using  namespace std;

struct Zone {
    int a, b;
};

bool cmp(const Zone &z1,  Zone &z2) {
    return z1.b < z2.b;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        Zone quJ[151];
        for (int i = 0; i < n; i++) cin >> quJ[i].a >> quJ[i].b;
        sort(quJ, quJ + n, cmp);

        int tot = 0;
        Zone tem = quJ[0];
        for (int i  = 1; i < n; i++) {
            if (tem.b < quJ[i].a) {
                tot++;
                tem = quJ[i];
            }
        }
        cout << tot + 1 << endl;

        }
        return 0;
}

