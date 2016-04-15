#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const string s1, const string s2) {
    return (s1 + s2) < (s2 + s1);
}

int main() {
    int t;
    cin >> t;
    
    while  (t--) {
        string s[101];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >>  s[i];
        }
        
        sort(s, s + n, cmp);
        
        for (int i = 0; i < n; i++) cout << s[i];
        cout << "\n";
    }
    
    return 0;
}
