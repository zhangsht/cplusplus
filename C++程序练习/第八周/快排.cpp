#include <iostream>
using namespace std;

template <class Record>
void quick_sort(Record* startPointer, Record* endPointer) {
    if(left<right) {
        int i = left;
        int j = right;
        int x = a[i];

        while(i<j)
        {
            while(i<j&&a[j]>x)
                j--;
            if(i<j){
                a[i] = a[j];
                i++;
            }
            while(i<j&&a[i]<x)
                i++;
            if(i<j){
             a[j] = a[i];
             j--;
            }
        }
        
        
        a[i] = x;
        quick_sort(a, left, i-1);
        quick_sort(a, i+1, right);
    }
}

int main() {
      int a[8] = {6 , 8 , 7, 5, 3, 1, 4, 2};
      quick_sort(a, a + 8);
      for (int i = 0; i < 8; i++) cout << a[i];
}
