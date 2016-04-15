#ifndef INHERITANCE_H
#define INHERITANCE_H
#include <iostream> 
class Base {
    public:
    Base();
    virtual void print();
    virtual ~Base();
};

class Derived :public Base {
    public:
    Derived();
    void print();
    ~Derived();
};
#endif

