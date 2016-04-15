#include <iostream>
//#include <map>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    int m, n;
    int a[301][11] = {0};

    while (cin >> m) {
        cin >> n;

        a[m][n]++;
    }
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j < B; j++) cout << a[i][j] << ' ';
        cout << a[i][B] << endl;
    }
}
