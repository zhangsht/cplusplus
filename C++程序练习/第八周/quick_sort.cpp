#include <iostream>
using namespace std;

template <class Record>
void quick_sort(Record* startPointer, Record* endPointer) {
   if (startPointer < endPointer) {
       Record *bottom = startPointer, *top =  endPointer - 1;
       Record privot = *startPointer;
       while (bottom < top)  {
           while (bottom < top && *top > privot) top--;
           if (bottom < top) {
               *bottom = *top;
               bottom++;
           }
           
           while (bottom < top && *bottom < privot) bottom++;
           if (bottom < top) {
               *top = *bottom;
               top--;
           }
       }
       
       *bottom = privot;
       quick_sort(startPointer, bottom);
       quick_sort(bottom + 1, endPointer);
   }
}

//int main() {
//      int a[12] = {6 , 8 , 7, -1, 2,10, 988, 5, 3, 1, 4, 2};
//      quick_sort(a, a + 12);
//      for (int i = 0; i < 12; i++) cout << a[i] << ' ';
//}
