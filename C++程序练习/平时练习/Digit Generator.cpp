// Problem#: 1325
// Author#: Reid Chan

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int digitsum_of_(int n)
{
    int t = n;
    while (t != 0) {
        n += (t % 10);
        t /= 10;
    }
    return n;
}

int main() {
    int t;
    string n;
    cin >> t;
    while (t--) {
        cin >> n;
        bool flag = true;
        int len = n.length();
        int num = atoi(n.c_str());
        for (int i = num - 9 * len; i < num; ++i) {
            if (digitsum_of_(i) == num) {
                cout << i << endl;
                flag = false;
                break;
            }
        }
        if (flag) { cout << 0 << endl; }
    }
    return 0;
}
