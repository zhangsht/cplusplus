#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int arr[11];
        for (int i = 1; i <= 10; i++) cin >> arr[i];
        int a= 1, b = 1;
        bool flag = true;
        stack<int> myst;
        while (b <= 10) {
            if (arr[b] == a) {
                a++, b++;
            } else if (!myst.empty() && arr[b] == myst.top()) {
                b++;
                myst.pop();
            } else if (a <= 10) {
                myst.push(a);
                a++;
            } else {
                flag = false;
                cout << "No\n";
                break;
            }
        }
        if (flag) cout << "Yes\n";
    }
    return 0;
}

