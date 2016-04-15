#include "vector.h"
int Vector::getValue(int i) {
    return data[i];
}
void Vector::setByFile(const char*fileName) {
    ifstream fin(fileName);
    for (int i = 0; i < 3; i++)
        fin >> data[i];
    fin.close();
}
void Vector::printToFile(const char*fileName) {
    ofstream fout(fileName);
    for (int i = 0; i < 3; i++)
        fout << data[i];
}
void Vector::sort(const char* cmp) {
    int n = 0, a[3];
    if (*cmp == 'a') {
    for (int i = 0; i < 3; i++)
       a[n++] = data[i];
    std::sort(a, a + 3);
    for (int i = 0; i < 3; i++)
        data[i] = a[--n];
    } else {
        for (int i = 0; i < 3; i++)
          a[n++] = data[i];
        std::sort(a, a + 3, greater<int>());
        for (int i = 0; i < 3; i++)
          data[i] = a[--n];
    }
}
void Vector::hear(const char* what, Vector m) {
    if (*what == 'I') {
        for (int i = 0; i < 3; i++)
          data[i] += m.getValue(i);
    } else {
        for (int i = 0; i < 3; i++)
          data[i] -= m.getValue(i);
    }
}

