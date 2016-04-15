#include <iostream>
#include "Matrix.h"
#include "Vector.h"
int main() {
    Matrix m, m2;
    m.setByFile("d:\\project.txt");
    ofstream first_flie("d:\\out_project.txt");
    m.printToFile("d:\\out_project.txt");
    char mode[50];
    cout << "Enter the mode of sorting:\n";
    cin >> mode;
    m.sort(mode);
    m2.setByFile("d:\\in_project2.txt");
    char operation[50];
    cout << "Enter the operation you want:\n";
    cin >> operation;
    m.hear(operation, m);
	return 0;
}

