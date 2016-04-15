#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
#include <iomanip>
using namespace std;
//template <class T1, class T2>
//class Member {
//    public:
//        Member(T1 _s, T2 _b) :s(_s), b(_b) {}
//        void print();
//    private:
//        T1 s;
//        T2 b;
//};
//template <class T1, class T2>
//void Member<T1, T2>::print() {
//    cout << s << '\t' << b << endl;
//} 
//template <class T>
//void Print(T &x) {
//    cout << x << " ";
//};
int main() {
    double p = 3.11234;
    cout << p << endl;
    cout << setprecision(2) << p << endl;
    cout << fixed << setprecision(2) << p << endl;
    cout << setfill('*') << setw(10) << p << endl;
    cout << scientific << p << endl;
//    vector<int> v(10);
//    fill(v.begin(), v.end(), 5);
//    for_each(v.begin(), v.end(), Print<int>);
//    typedef Member<string, int> M;
//    vector<M> v;
//    v.push_back(M("vshcg", 2342));
//    v.push_back(M("bsjdc", 3784));
//    vector<M>::iterator it = v.begin();
//    while (it != v.end())
//       (it++)->print();
//    v.front().print();
//    int a[] = {1, 2, 3};
//    vector<int> v;
//    v.assign(a, a + 3);
//    v.assign(5, 2);
//    vector<int>::iterator it = v.begin();
//    while (it != v.end())
//      cout << *it++ << ' ';
//    cout << endl;
    return 0;
}

