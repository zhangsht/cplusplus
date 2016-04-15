#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
bool bound(int &a) {
    return a >= 10;
}
int main() {
    int value;
    int a[10] = {22, 4, 3, 56, 4, 12, -2, 98, 34, 12};
    vector<int> v(a, a + 10);
    vector<int>::reverse_iterator r_it;
    r_it = find(v.rbegin(), v.rend(), 12);
    cout << v.rend() - r_it << endl;
//    while (cin >> value)
//      v.push_back(value);
//    cin.clear();
//    cout << accumulate(v.begin(), v.end(), 0) << endl; 
//   vector<int>::iterator it;
   sort(v.begin(), v.end());
//   for (it = v.begin(); it != v.end(); it++)
//     cout << *it << ' ';
//   cout << endl;
//   v.erase(unique(v.begin(), v.end()), v.end());
//   for (it = v.begin(); it != v.end(); it++)
//     cout << *it << ' ';
//   cout << endl;
//   list<int> lst, lst2;
//   replace_copy(v.begin(), v.end(), inserter(lst, lst.begin()), 22, 4);
//   list<int>::iterator it2;
//   for (it2 = lst.begin(); it2 != lst.end(); it2++)
//     cout << *it2 << ' ';
//   cout << endl;
//    int searchValue;
//    cin >> searchValue;
//    cout << count(v.begin(), v.end(), searchValue) << endl;
//    cout << count_if(v.begin(), v.end(), bound) << endl;
    return 0;
}

