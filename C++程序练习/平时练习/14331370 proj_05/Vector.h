#ifndef VCTOR_H
#define VECTOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
class Vector {
    public:
    void setByFile(const char*);
    void printToFile(const char*);
    void sort(const char*);
    void hear(const char*, Vector);
    int getValue(int i);
    private:
       int data[3];
}; 
#endif
