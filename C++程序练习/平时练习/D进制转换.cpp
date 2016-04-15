#include <iostream>
#include <stack>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int arr[11];
        for (int i = 1; i <= 10; i++)
            cin >> arr[i];
        stack<int> myst;
        int a = 1, b = 1;
        bool flag = true;
        while (b <= 10) {
            if (arr[b] == a) {
                a++;
                b++;
            } else if (!myst.empty() && myst.top() == arr[b]) {
                myst.pop();
                 b++;
            } else if (a <= 10) {
                myst.push(a);
                a++;
            } else {
                cout << "No\n";
                flag = false;
                break;
            }
        }
        if (flag) cout << "Yes\n";
    }
    return 0;
}
