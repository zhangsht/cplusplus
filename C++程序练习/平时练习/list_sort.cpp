#include <iostream>
#include <list>
#include <iterator>
#include <cctype>
using namespace std;
bool cmp(const string& f, const string &s) {
    unsigned int i = 0;
    while (i < f.size() && i < s.size()) {
        if (tolower(f[i]) < tolower(s[i])) return true;
        else if (toupper(f[i] > toupper(s[i]))) return false;
        i++;
    }
    return (f.size() < s.size());
}
int main() {
    list<string> mylist;
    list<string>::iterator it;
    mylist.push_back("one");
    mylist.push_back("two");
    mylist.push_back("Three");
    mylist.sort();
    copy(mylist.begin(), mylist.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    mylist.sort(cmp);
    copy(mylist.begin(), mylist.end(), ostream_iterator<string>(cout, " "));
    return 0;
}
