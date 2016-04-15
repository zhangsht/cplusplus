#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
//    map<char, int> m;
//     m['a'] = 10;
//     m['b'] = 20;
//     m['c'] = 30;
//     pair<map<char, int>::iterator, map<char, int>::iterator>p;
//     p = m.equal_range('b');
//     cout << p.first->first << ' ' << p.first->second << endl;
//     cout << p.second->first << ' ' << p.second->second << endl;
    map<int, int> m1, m2;
    m1.insert(pair<int, int>(2, 10));    
    m1.insert(pair<int, int>(1, 20));    
    m1.insert(pair<int, int>(3, 30));
    map<int, int>::reverse_iterator it = m1.rbegin();
    for (; it != m1.rend(); it++) {
        cout << it->second << ' ';
    }
    cout << endl;
    int c = 0, i;
    for (i = 0; i < 5; i++) {
        if (m1.count(i)) {
            cout << i << " is in the map\n";
            c++;
        }
    }
    cout << c;
    return 0;
}

