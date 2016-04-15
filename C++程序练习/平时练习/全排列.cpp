// Problem#: 15982
// Submission#: 3994535
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        for (int i = 0; i < n; i++) {
            str += 49 + i;
        }
        cout << str << endl;
        while (next_permutation(str.begin(), str.end())) {
            cout << str << endl;
        }
    }
    return 0;
}
