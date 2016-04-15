#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const int & a, const int &b) {
    return a > b;
}
int main() {
    int n, k;
    while (cin >> n) {
        cin >> k;
        vector<int> a;
        int tem;
        for (int i = 0; i < n; i++) {
            cin >> tem;
            a.push_back(tem);
        }
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < k - 1; i++) cout << a[i] << ' ';
        cout << a[k - 1] << endl;
    }
}
