#include <iostream>
#include <list>
#include <iterator>
using namespace std;
bool is_single (const int &value) {
    return (value < 10);
}
struct is_odd {
    bool operator() (const int &value) {
        return (value % 2 == 1);
    }
};
int main() {
    int a[] = {12, 13, 45, 7, 8, 45, 24, 19};
    list<int> mylist(a, a + 8);
    copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    mylist.remove_if(is_single);
    mylist.remove_if(is_odd());
    list<int>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); it++)
      cout << *it << ' '; 
    return 0;
}
