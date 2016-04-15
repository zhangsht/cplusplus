#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, t;
    while (cin >> n) {
        cin >> t;
        
        vector<vector<int> > groups(t);
        
        int tem, mod;
        for (int i = 0; i < n; i++) {
            cin >> tem;
            mod = tem % t;
            groups[mod].push_back(tem);
        }
        
        double tot = 0;
        for (int i = 0; i < t; i++) {
            int len2 = groups[i].size();
            tot += len2 * (len2 + 1) / 2;
            for (int j = len2 - 1; j >= 0; j--) cout << groups[i][j] << ' ';
            cout << endl;
        }
        cout << setiosflags(ios::fixed) << setprecision(3) << tot / n << endl;
    }
    return 0;
}

