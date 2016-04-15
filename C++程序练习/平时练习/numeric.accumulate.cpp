#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
#include  <vector>
//#include <list>
#include <iterator>
using namespace std;
//bool is_single (const int &value) {
//    return (value < 10);
//}
//struct is_odd {
//    bool operator() (const int &value) {
//        return (value % 2 == 1);
//    }
//};
int main() {
//    int i = 0;
    int a[] = {1, 1, 5, 7, 8, 4, 4, 9};
    vector<int> v(a, a + 8);
    sort(v.begin(), v.end());
    vector<int>::iterator it = unique(v.begin(), v.end());
    v.erase(it, v.end());
  //  replace_copy(a, a + 8, back_inserter(v), 4, -1);
//    int * t = copy(a, a + 8, b);
//    if (t == b + 8) {
//        cout << "tt\n";
//    }
 //   copy(b, b + 8, ostream_iterator<int>(cout, " "));
//    int b[] = {1, 1, 5, 7, 8, 4, 4, 9};
    //int sum = accumulate(a, a + 8, i);
//    if (equal(a, a + 8, b)) {
//        cout << "minmin\n";
//    }
    //cout << sum;
//    vector<int> v; 
//    fill_n(back_inserter(v), 4, 10);
   copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  //  copy(a, a + 8, ostream_iterator<int>(cout, " "));
    return 0;
}

