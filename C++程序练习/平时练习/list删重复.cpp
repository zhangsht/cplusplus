#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    string s[5] = {"sdcuj", "fueibkus", "tyuhvdj", "fueibkus", "sdcuj"};
    list<string> mylist(s, s + 5);
    list<string>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); it++)
      cout << *it << endl;
    cout << endl; 
    mylist.sort();
    mylist.unique();
    for (it = mylist.begin(); it != mylist.end(); it++)
      cout << *it << endl;
    return 0;
}

