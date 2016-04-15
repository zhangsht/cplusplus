#include <iostream>
//template <class T>
//bool make2D(T** &x, int row, int col) {
//    x = new T*[row];
//    for (int i = 0; i < col; i++)
//      x[i] = new T[col];
//    return true;
//}
int *a = new int[10];
template <class T, int N>
bool changeSize1D(T (&x)[N], int size) {
    std::cout << N << std::endl;
    delete [] a;
    a = new T[N];
    for (int i = 0; i < N; i++)
       a[i] = x[i];
}
int main() {
   int arry[5] = {0};
   changeSize1D(arry, 10);
   delete [] a;
   a = NULL;
   return 0;
} 

