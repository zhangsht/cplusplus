#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int a[11][11], b[11][11];
        int c[11][11] = {0};
        int i, j, k;
        for (i = 0; i < n; i++)
          for (j = 0; j < n; j++)
            cin >> a[i][j];
        for (i = 0; i < n; i++)
         for (j = 0; j < n; j++)
            cin >> b[i][j];
            
        for (i = 0; i < n; i++)
          for (j = 0; j < n; j++)
             for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++)
                cout << c[i][j] << ' ';
            cout << c[i][j] << endl;
        }
    }
    return 0; 
}

