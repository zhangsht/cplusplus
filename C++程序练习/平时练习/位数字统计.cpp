#include <iostream>
#include <string>
using namespace std;
int main() {
    int a[10] = {0};
    string int_str;
    cin >> int_str;
    int len = int_str.length();
    for (int i = len - 1; i >= 0; i--) {
        a[int_str[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (a[i]) cout << i << ":" << a[i] << endl;
    }
    return 0;
}
