#include<iostream>
#include<cstdlib>
using namespace std;

class heap {

private:

    int elements[1000];
    int size;
    void swap(int index1, int index2) {

        int temp = elements[index1];
        elements[index1] = elements[index2];
        elements[index2] = temp;
    }

    void reheapDown(int node) {

        int leftChild = (node + 1) * 2 - 1;
        int rightChild = (node + 1) * 2;
        int bigger = node;
        if (leftChild < size) {

            if (elements[leftChild] > elements[bigger])
            bigger = leftChild;

            if (rightChild < size) {

                if (elements[rightChild] > elements[bigger])
                bigger = rightChild;
            }
        }

        if (node == bigger) return;
        swap(node, bigger);
        reheapDown(bigger);
    }

    void reheapUp(int node) {

        if (node <= 0) return;
        int parent = (node + 1) / 2 - 1;

        if (elements[parent] < elements[node]) {
#include<iostream>
#include<cstdlib>
using namespace std;

class heap {

private:

    int elements[1000];
    int size;
    void swap(int index1, int index2) {

        int temp = elements[index1];
        elements[index1] = elements[index2];
        elements[index2] = temp;
    }

    void reheapDown(int node) {

        int leftChild = (node + 1) * 2 - 1;
        int rightChild = (node + 1) * 2;
        int bigger = node;
        if (leftChild < size) {

            if (elements[leftChild] > elements[bigger])
            bigger = leftChild;

            if (rightChild < size) {

                if (elements[rightChild] > elements[bigger])
                bigger = rightChild;
            }
        }

        if (node == bigger) return;
        swap(node, bigger);
        reheapDown(bigger);
    }

    void reheapUp(int node) {

        if (node <= 0) return;
        int parent = (node + 1) / 2 - 1;

        if (elements[parent] < elements[node]) {

            swap(parent, node);
            reheapUp(parent);
        }
    }

public:

    heap() {

        for (int i = 0; i < 1000; i++)
        elements[i] = 0;
        size = 0;
    }
    void add(int data) {

        elements[size++] = data;
        reheapUp(size - 1);
    }

    void remove() {

        if (size <= 0) return;

        swap(0, size - 1);
        size--;
        reheapDown(0);
    }

    int getSize() {

        return size;
    }

    int *getElements() {

        return elements;
    }
};


void print(heap& p, int n) {

    int* elements = p.getElements();
    for (int i = 0; i < n; i++) {

        if (i == 0) {

            cout << elements[i];
        } else {

            cout << " " << elements[i];
        }
    }

    cout << endl;
}

int main() {

    int n;
    while (cin >> n && n != -1) {

        heap h;
        for (int i = 0; i < n; i++) {

            int temp;
            cin >> temp;
            h.add(temp);
        }

        print(h, n);
        while (h.getSize() > 1) {
            h.remove();
            print(h, n);
        }
    }

//      heap p;
//    for (int i = 0; i < 1000; i++) {
//
//        p.add(rand() % 1000);
//    }
//
//    for (int i = 0; i < 1005; i++) {
//
//        p.remove();
//    }
//
//    print(p, 1000);
}

            swap(parent, node);
            reheapUp(parent);
        }
    }

public:

    heap() {

        for (int i = 0; i < 1000; i++)
        elements[i] = 0;
        size = 0;
    }
    void add(int data) {

        elements[size++] = data;
        reheapUp(size - 1);
    }

    void remove() {

        if (size <= 0) return;

        swap(0, size - 1);
        size--;
        reheapDown(0);
    }

    int getSize() {

        return size;
    }

    int *getElements() {

        return elements;
    }
};


void print(heap& p, int n) {

    int* elements = p.getElements();
    for (int i = 0; i < n; i++) {

        if (i == 0) {

            cout << elements[i];
        } else {

            cout << " " << elements[i];
        }
    }

    cout << endl;
}

int main() {

    int n;
    while (cin >> n && n != -1) {

        heap h;
        for (int i = 0; i < n; i++) {

            int temp;
            cin >> temp;
            h.add(temp);
        }

        print(h, n);
        while (h.getSize() > 1) {
            h.remove();
            print(h, n);
        }
    }

//      heap p;
//    for (int i = 0; i < 1000; i++) {
//
//        p.add(rand() % 1000);
//    }
//
//    for (int i = 0; i < 1005; i++) {
//
//        p.remove();
//    }
//
//    print(p, 1000);
}

