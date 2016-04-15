#include <iostream>
template <class T>
inline void swap(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}
template <class T>
void Perm(T a[], int k,  int m) {
    int i;
    if (k == m) {
        for (i = 0; i <= m; i++)
          std::cout << a[i] << ' ';
        std::cout << std::endl;
    } else
        for (i = k; i <= m; i++) {
            swap(a[k], a[i]);
            Perm(a, k + 1, m);
            swap(a[k], a[i]);
        }
    return;
}
int man() {
    int arry[5] = {2, 3, 4, 5, 6};
    Perm(arry, 0, 4);
    return 0;
} 

