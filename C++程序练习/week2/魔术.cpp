#include <iostream>
using namespace std;

int main() {
      int t;
      cin >> t;
      while (t--) {
          int m, n, j = 1;
          int a[27] = {0};
          cin >> m;
          for (int i = 1; i <= m; i++) {
              n = 1;
              do {
                  if (j > m) j = 1;
                  if (a[j]) j++;
                  else {
                      if (n == i) a[j] = i;
                      j++, n++;
                  }
              } while (n <= i);
          }
          for (int i = 1; i <= m; i++) cout << a[i] << ' ';
          cout << endl;
      }
}

