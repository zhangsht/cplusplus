#include <iostream>
using namespace std;

int solved(int steps) {
    if (steps < 3) return steps;
    return solved(steps - 1) + solved(steps - 2);
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int high;
        cin >> high;
        cout << solved(high) << endl;
    }
    return 0;
}

