#include <iostream>
//#include <map>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int m, n, t;
    int at[301][11][3] = {0};
    int wa[301][11][2] = {0};
    while (cin >> m) {
        cin >> n >> t;

        at[m][n][t]++;
        wa[m][n][t]++;
    }
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j < B; j++) cout << at[i][j][1] << ' ' << wa[i][j][0] << ' ';
        cout << at[i][B][1] << ' ' << wa[i][B][0] << endl;
    }
}
