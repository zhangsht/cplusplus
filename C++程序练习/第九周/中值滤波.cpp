#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[11];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
    cout << a[n - 1] << endl;
    if (n % 2) cout << a[n / 2];
    else cout << (a[n / 2] + a[n / 2 - 1]) / 2;
}
