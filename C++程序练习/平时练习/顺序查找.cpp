#include <iostream>
template <class T, int N>
int search(T (&a)[N], T x) {
    int i; 
    for (i = 0; i < N && a[i] != x; i++);
    if (i == N) return -1;
    return i + 1;
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    std::cout << search(a, 3);
    return 0;
}
