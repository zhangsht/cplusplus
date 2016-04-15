#include <iostream>
//#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);
    cout << accumulate(a, a + 5, 0) << endl;
    vector<int>::reverse_iterator rit = v.rbegin();
    advance(rit, 3);
    cout << *rit << endl; 
    copy(a, a + 4, inserter(v, v.begin()));
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
      cout << *it << ' ';
    return 0;
}

