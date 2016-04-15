#include <iostream>
#include <vector>
using namespace std;

bool search(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return true;
        }
    }
    return false;
}
int main() {
    int m, n;
    while (cin >> m) {
        cin >> n;
        
        int a[101], b[101];
        vector<int> v1, v2, v3;
        int i, len1 = 0, len2 = 0, len3 = 0;
        
        for (i = 0; i < m; i++) cin >> a[i];
        for (i = 0; i < n; i++) {
            cin >> b[i];
            if (!search(a, m, b[i])) {
                v2.push_back(b[i]);
                len2++;
            }
        }
        
        for (i = 0; i < m; i++) {
            if (search(b, n, a[i])) {
                v1.push_back(a[i]);
                len1++;
            } else {
                v3.push_back(a[i]);
                len3++;
            }
        }
        
        for (i = 0; i < len1; i++) cout << v1[i] << ' ';
        cout << endl;
        for (i = 0; i < m; i++) cout << a[i] << ' ';
        for (i = 0; i < len2; i++) cout << v2[i] << ' ';
        cout << endl;
        for (i = 0; i < len3; i++) cout << v3[i] << ' ';
         cout << endl;

    }
}
