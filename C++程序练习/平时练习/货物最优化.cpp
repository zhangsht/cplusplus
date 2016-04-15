#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct MoonCake {
    double l, m;
    double price;
}s[1000];

bool cmp(const MoonCake m1, const MoonCake m2) {
    return m1.price < m2.price;
}
int main() {
    int n, tot;
    cin >> n >> tot;
    for (int i = 0; i < n; i++)
      cin >> s[i].l;
    for (int i = 0; i < n; i++) {
        cin >> s[i].m;
        s[i].price = s[i].m / s[i].l;
    }
    sort(s, s + n, cmp);
    int temp;
    double sum = 0;
    for (int i = n - 1; tot > 0 && i >= 0; i--) {
        temp = (tot > s[i].l ? s[i].l : tot);
        sum += temp * s[i].price;
        tot -= temp;
    }
    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}

