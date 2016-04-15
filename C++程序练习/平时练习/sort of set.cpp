#include <iostream>
#include <set>
using namespace std;
int main() {
    int arry[6] = {1, 3, 5, 2, 6, 4};
    set<int> myset(arry, arry + 6);
    set<int>::iterator it = myset.begin();
    for (; it != myset.end(); it++)
      cout << *it << ' ';
    cout << endl;
    return 0;
}

