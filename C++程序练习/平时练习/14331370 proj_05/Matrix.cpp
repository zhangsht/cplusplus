#include "Matrix.h"
int Matrix::getValue(int i, int j) {
    return data[i][j];
}
void Matrix::setByFile(const char*fileName) {
    ifstream fin(fileName);
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        fin >> data[i][j];
    fin.close();
}
void Matrix::printToFile(const char*fileName) {
    ofstream fout(fileName);
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        fout << data[i][j];
}
void Matrix::sort(const char* cmp) {
    int n = 0, a[9];
    if (*cmp == 'a') {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
       a[n++] = data[i][j];
    std::sort(a, a + 9);
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        data[i][j] = a[--n];
    } else {
        for (int i = 0; i < 3; i++)
         for (int j = 0; j < 3; j++)
          a[n++] = data[i][j];
        std::sort(a, a + 9, greater<int>());
        for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        data[i][j] = a[--n];
    }
}
void Matrix::hear(const char* what, Matrix m) {
    if (*what == 'I') {
        for (int i = 0; i < 3; i++)
         for (int j = 0; j < 3; j++)
          data[i][j] += m.getValue(i, j);
    } else {
        for (int i = 0; i < 3; i++)
         for (int j = 0; j < 3; j++)
        data[i][j] -= m.getValue(i, j);
    }
}

