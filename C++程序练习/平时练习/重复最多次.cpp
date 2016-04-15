#include <iostream>
#include <string>
//#include <vector>
#include <algorithm>
using namespace std;
template<class T>
T find(T* first, T* last) {
    sort(first, last);
    int count = 1, max = 1;
    T maxValue;
    T *cur, *pre = first;
    for (cur = first++; cur != last; cur++) {
        while (*cur == *pre) {
            count++;
            pre = cur;
            cur++;
        }
        if (count > max) {
            max = count;
            maxValue = *pre;
        }
        pre = cur;
    }
    return maxValue;
}

template<class T>
bool cmp(T s1, T s2) {
    return s1 < s2; 
}
int main() {
    int a[12] = {2, 4, 5, 3, 2, 5, 5, 8, 12, 4, 5, 9};
    cout << find(a, a + 12) << endl;
    bool t = cmp<string>("skkfd", "vdjd");
    cout << t;
    return 0;
}

