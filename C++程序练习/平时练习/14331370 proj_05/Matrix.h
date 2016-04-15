#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
class Matrix{
    public:
    void setByFile(const char*);
    void printToFile(const char*);
    void sort(const char*);
    void hear(const char*, Matrix);
    int getValue(int i, int j);
    private:
       int data[3][3];
}; 
#endif
