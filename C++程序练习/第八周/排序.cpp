#include <iostream>
using namespace std;

int main() {
    int t, n;
    int a[1001];
    
    cin >> t;
    while (t--) {
        cin >> n;
        
        for (int i = 0; i < n; i++) cin >> a[i];
        
        for (int i = 0; i < n - 1; i++) {
            int k = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[k])   k = j;
            }
            
            int t = a[i];
            a[i] = a[k];
            a[k] = t;
            
            for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
            cout << a[n - 1] << endl;
        }
    }
    return 0;
}

