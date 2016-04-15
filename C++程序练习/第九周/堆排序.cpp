#include <vector>
#include <cstdio>
using namespace std;
int count = 0;
vector<int> array;

void print() {
      for (int i = 0; i < count - 1; i++) printf("%d ", array[i]);
      printf("%d\n", array[count - 1]);
}
void insert_heap(int &current, int low, int high) {
    int large;
    large = 2 * low + 1;
    while (large <= high) {
        if (large < high && array[large] < array[large + 1]) large++;
        if (current >= array[large]) break;
        else {
            array[low] = array[large];
            low = large;
            large = 2 * low + 1;
        }
    }
    array[low] = current;
}


void build_heap() {
    int low;
    for (low = count  / 2 - 1; low >=0; low--) {
        int current = array[low];
        insert_heap(current, low, count - 1);
    }
}

void heap_sort() {
    int current;
    int last_unsorted;
    build_heap();

    print();
    for (last_unsorted = count - 1; last_unsorted > 0; last_unsorted--) {
        current = array[last_unsorted];
        array[last_unsorted] = array[0];
        insert_heap(current, 0, last_unsorted - 1);
        
        print();
    }
}

int main() {
    while (scanf("%d", &count) != EOF) {
        array.clear();
        
        int  tem;
        for (int i = 0; i < count; i++) {
            scanf("%d", &tem);
            array.push_back(tem);
        }
        
        heap_sort();
    }
    return 0;
}
